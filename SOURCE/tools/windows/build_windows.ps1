# Native Windows build. No Python, WSL, Wibo, or downloaded dependencies required.
# LinuxRunner/PreparedSdk are only for the documented cross-platform regression.
[CmdletBinding()]
param(
    [ValidateSet('both','normal','diagnostic')][string]$Kind = 'both',
    [switch]$VerifyRelease,
    [string]$LinuxRunner,
    [string]$PreparedSdk
)
Set-StrictMode -Version 2.0
$ErrorActionPreference = 'Stop'
$source = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '../..'))
$root = [IO.Path]::GetFullPath((Join-Path $source '..'))
$isNativeWindows = [Environment]::OSVersion.Platform -eq [PlatformID]::Win32NT
$work = $null
$lock = $null
$logWriter = $null
$successful = $false

function Note([string]$Text) {
    Write-Host $Text
    if ($null -ne $script:logWriter) { $script:logWriter.WriteLine($Text); $script:logWriter.Flush() }
}
function Quote-Argument([string]$Value) {
    # CommandLineToArgvW quoting, also used by .NET ProcessStartInfo on Unix.
    return '"' + ([regex]::Replace(([regex]::Replace($Value, '(\\*)"', '$1$1\"')), '(\\+)$', '$1$1')) + '"'
}
function Run-Tool([string]$Exe, [string[]]$ToolArgs, [string]$Expected) {
    $tool = Join-Path $script:sdk ('BIN/' + $Exe)
    if ($Expected -and (Test-Path -LiteralPath $Expected)) { Remove-Item -LiteralPath $Expected -Force }
    $info = New-Object Diagnostics.ProcessStartInfo
    $info.UseShellExecute = $false
    $info.CreateNoWindow = $true
    $info.RedirectStandardOutput = $true
    $info.RedirectStandardError = $true
    $info.WorkingDirectory = $script:game
    if ($script:isNativeWindows) {
        $info.FileName = $tool
        $arguments = $ToolArgs
    } else {
        $info.FileName = $LinuxRunner
        $arguments = @('-C', $script:game, $tool) + $ToolArgs
    }
    $info.Arguments = (($arguments | ForEach-Object { Quote-Argument $_ }) -join ' ')
    # Relative THOME plus relative inputs avoids the Toshiba parser's long-path
    # and space handling, including extraction beneath a user folder with spaces.
    $info.EnvironmentVariables['THOME'] = '..\T900'
    Note ('RUN ' + $Exe + ' ' + ($ToolArgs -join ' '))
    $proc = New-Object Diagnostics.Process
    $proc.StartInfo = $info
    try {
        if (-not $proc.Start()) { throw ('Could not start ' + $Exe) }
        $stdout = $proc.StandardOutput.ReadToEndAsync()
        $stderr = $proc.StandardError.ReadToEndAsync()
        $proc.WaitForExit()
        $text = $stdout.Result + $stderr.Result
        if ($text) { Note $text.TrimEnd() }
        Note ('EXIT ' + $proc.ExitCode)
        if ($proc.ExitCode -ne 0 -or $text -match '(?i)(?:Error|Fatal)\s*[-:]|runtime error|\bR6\d{3}\b') {
            throw ('Toshiba tool failed: ' + $Exe + '. See WINDOWS_BUILD_LOG.txt.')
        }
        if ($Expected -and (-not (Test-Path -LiteralPath $Expected -PathType Leaf) -or (Get-Item -LiteralPath $Expected).Length -eq 0)) {
            throw ('Toshiba did not produce a fresh output: ' + $Expected)
        }
    } finally { $proc.Dispose() }
}

try {
    if (-not $isNativeWindows -and (-not $LinuxRunner -or -not $PreparedSdk)) {
        throw 'Use BUILD_MY_ROM.bat on Windows; use tools/build_final.py on Linux/WSL2.'
    }
    # Deny concurrent builders in this extraction; leave the lock file harmlessly
    # in place. Exclusive access is released on success, failure, or interruption.
    $lock = [IO.File]::Open((Join-Path $root '.windows-build.lock'), [IO.FileMode]::OpenOrCreate, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
    $logWriter = New-Object IO.StreamWriter((Join-Path $root 'WINDOWS_BUILD_LOG.txt'), $false)
    $logWriter.AutoFlush = $true
    Note 'BATMAN V102: clean build from current source'
    $manifest = Get-Content -LiteralPath (Join-Path $source 'tools/build_sources.json') -Raw | ConvertFrom-Json
    $allSources = @($manifest.c) + @($manifest.asm) + @($manifest.library_asm)
    $stems = @($allSources | ForEach-Object { [IO.Path]::GetFileNameWithoutExtension($_).ToLowerInvariant() })
    if (@($stems | Select-Object -Unique).Count -ne $stems.Count) { throw 'Duplicate object basenames in manifest' }
    foreach ($exe in @('cc900.exe','asm900.exe','tulink.exe','tuconv.exe')) {
        if (-not (Test-Path -LiteralPath (Join-Path $source ('T900/BIN/' + $exe)) -PathType Leaf)) {
            throw ('Missing SOURCE/T900/BIN/' + $exe + '. Extract the complete ZIP first.')
        }
    }
    foreach ($path in @($manifest.c) + @($manifest.asm)) {
        if (-not (Test-Path -LiteralPath (Join-Path $source ('game/' + $path)) -PathType Leaf)) { throw ('Missing source: ' + $path) }
    }
    Add-Type -Path (Join-Path $PSScriptRoot 'S24ToRom.cs')
    $work = Join-Path ([IO.Path]::GetTempPath()) ('BatmanBuild_V102_' + [Guid]::NewGuid().ToString('N'))
    New-Item -ItemType Directory -Path $work | Out-Null
    $sdkSource = Join-Path $source 'T900'
    if (-not $isNativeWindows) { $sdkSource = [IO.Path]::GetFullPath($PreparedSdk) }
    Copy-Item -LiteralPath $sdkSource -Destination (Join-Path $work 'T900') -Recurse
    $sdk = Join-Path $work 'T900'
    $identities = Get-Content -LiteralPath (Join-Path $root 'DOCUMENTATION/FINAL_ROM_IDENTITIES.json') -Raw | ConvertFrom-Json
    $results = @()
    foreach ($label in @('normal','diagnostic')) {
        if ($Kind -ne 'both' -and $Kind -ne $label) { continue }
        Note ('BUILD ' + $label.ToUpperInvariant())
        $game = Join-Path $work ('game_' + $label)
        Copy-Item -LiteralPath (Join-Path $source 'game') -Destination $game -Recurse
        New-Item -ItemType Directory -Path (Join-Path $game 'build') -Force | Out-Null
        # Remove any outputs accidentally included by a future source editor.
        Get-ChildItem -LiteralPath (Join-Path $game 'build') -Filter '*.rel' | Remove-Item -Force
        foreach ($name in @('batman.abs','batman.map','batman.s24')) {
            $path = Join-Path $game $name
            if (Test-Path -LiteralPath $path) { Remove-Item -LiteralPath $path -Force }
        }
        if ($label -eq 'diagnostic') {
            $path = Join-Path $game 'src/graphics_diff.asm'
            $text = [IO.File]::ReadAllText($path).Replace("`r`n", "`n")
            $re = New-Object Text.RegularExpressions.Regex('        push bc\n')
            $text = $re.Replace($text, "        push xiz`n        ld iz,0`n        push bc`n", 1)
            $text = [regex]::Replace($text, '(        ld \(xde(?:\+\d+)?\),xwa)', ('$1' + "`n        inc 4,iz"))
            $text = $text.Replace('        ld (xde),wa', "        ld (xde),wa`n        inc 2,iz")
            $text = $text.Replace('        ret z','        jp z,diag_diff_return').Replace("        ret`n", "        jp diag_diff_return`n")
            $text = $text.Replace('        end', "diag_diff_return:`n        ld hl,iz`n        pop xiz`n        ret`n        end")
            [IO.File]::WriteAllText($path, $text.Replace("`n", "`r`n"), [Text.Encoding]::ASCII)
        }
        $flags = @('-A','-c','-O3','-Nb2','-Isrc','-Ivendor/ngpc/core','-Ivendor/ngpc/gfx',
            '-DNGP_ENABLE_DEBUG=0','-DNGP_PROFILE_RELEASE=1','-DNGP_ENABLE_SOUND=0',
            '-DNGP_ENABLE_FLASH_SAVE=0','-DNGP_NEAR=__near')
        if ($label -eq 'diagnostic') { $flags += @('-DHW_PERF=1','-DHW_PERF_VERSION=68') }
        $objects = @()
        foreach ($path in @($manifest.c)) {
            $obj = 'build/' + [IO.Path]::GetFileNameWithoutExtension($path) + '.rel'
            Run-Tool 'cc900.exe' ($flags + @($path,'-o',$obj)) (Join-Path $game $obj)
            $objects += $obj
        }
        foreach ($path in @($manifest.asm) + @($manifest.library_asm)) {
            $inputPath = $path
            if (@($manifest.library_asm) -contains $path) { $inputPath = '../T900/LIB/SRC/' + $path }
            $obj = 'build/' + [IO.Path]::GetFileNameWithoutExtension($path) + '.rel'
            Run-Tool 'asm900.exe' @($inputPath,'-o',$obj) (Join-Path $game $obj)
            $objects += $obj
        }
        Run-Tool 'tulink.exe' (@('-la','-o','batman.abs','ngpc.lcf') + $objects) (Join-Path $game 'batman.abs')
        Run-Tool 'tuconv.exe' @('-Fs24','batman.abs') (Join-Path $game 'batman.s24')
        if (@(Get-ChildItem -LiteralPath $game | Where-Object { $_.Name -match '^batman\.o[0-9a-f]{2}$' }).Count) {
            throw 'Converter emitted split overlays: invalid cartridge load images'
        }
        $name = 'Batman_V1.0.2.ngc'
        if ($label -eq 'diagnostic') { $name = 'Batman_V1.0.2_Diags.ngc' }
        $staged = Join-Path $work $name
        $edgeSource = [IO.File]::ReadAllText((Join-Path $game 'src/vehicle_edge_pixels_all.asm'))
        $hash = [BatmanRom]::Convert((Join-Path $game 'batman.s24'), (Join-Path $game 'batman.map'), $staged, $edgeSource.Contains('chg 0,l'))
        $expected = $identities.$label.sha256
        if ($VerifyRelease -and $hash -ne $expected) { throw ('Release hash mismatch: ' + $name) }
        $results += [pscustomobject]@{kind=$label; file=$name; bytes=4194304; sha256=$hash; matches_release=($hash -eq $expected)}
        Note ('VALIDATED ' + $name + ' SHA256 ' + $hash)
        $evidence = Join-Path $root ('EVIDENCE/WINDOWS_BUILD/' + $label)
        New-Item -ItemType Directory -Path $evidence -Force | Out-Null
        foreach ($artifact in @('batman.map','batman.abs','batman.s24')) {
            Copy-Item -LiteralPath (Join-Path $game $artifact) -Destination $evidence -Force
        }
    }
    # Only publish after EVERY requested image has compiled and passed checks.
    foreach ($result in $results) {
        foreach ($directory in @((Join-Path $root 'OUTPUT'), (Join-Path $source 'OUTPUT'))) {
            New-Item -ItemType Directory -Path $directory -Force | Out-Null
            Copy-Item -LiteralPath (Join-Path $work $result.file) -Destination (Join-Path $directory ($result.file + '.new')) -Force
            Move-Item -LiteralPath (Join-Path $directory ($result.file + '.new')) -Destination (Join-Path $directory $result.file) -Force
        }
    }
    $report = [pscustomobject]@{passed=$true; runtime=([Environment]::OSVersion.ToString()); native_windows=$isNativeWindows; clean=$true; results=$results}
    $report | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath (Join-Path $root 'EVIDENCE/WINDOWS_BUILD/RESULT.json') -Encoding UTF8
    Note 'BUILD COMPLETE. Newly compiled ROMs are in OUTPUT and SOURCE/OUTPUT.'
    $successful = $true
} catch {
    Note ('BUILD FAILED: ' + $_.Exception.Message)
    Note 'Existing OUTPUT ROMs have not been replaced unless the whole requested build passed.'
} finally {
    if ($null -ne $logWriter) { $logWriter.Dispose() }
    if ($null -ne $lock) { $lock.Dispose() }
    if ($null -ne $work -and (Test-Path -LiteralPath $work)) { Remove-Item -LiteralPath $work -Recurse -Force -ErrorAction SilentlyContinue }
}
if (-not $successful) { exit 1 }
exit 0
