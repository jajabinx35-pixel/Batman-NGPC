@echo off
setlocal DisableDelayedExpansion
set "POWERSHELL_TELEMETRY_OPTOUT=1"
set "POWERSHELL_UPDATECHECK=Off"
pushd "%~dp0"
if errorlevel 1 exit /b 1
where powershell.exe >nul 2>&1
if errorlevel 1 goto missing_powershell
echo Batman M66 - building the normal and hardware diagnostic ROMs.
echo This can take several minutes. A full log is saved to WINDOWS_BUILD_LOG.txt.
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0SOURCE\tools\windows\build_windows.ps1"
set "BUILD_RESULT=%errorlevel%"
if "%BUILD_RESULT%"=="0" goto success
echo.
echo BUILD FAILED. Read WINDOWS_BUILD_LOG.txt for the actual error.
goto done
:success
echo.
echo BUILD COMPLETE - both newly compiled ROMs are in the OUTPUT folder.
goto done
:missing_powershell
echo Windows PowerShell was not found. This launcher requires Windows 10 or 11.
set "BUILD_RESULT=1"
:done
if /I "%~1"=="--no-pause" goto exit_build
pause
:exit_build
popd
exit /b %BUILD_RESULT%
