using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;
using System.Collections.Generic;
using System.Security.Cryptography;

// Compatible with the compiler supplied by Windows PowerShell 5.1 / .NET 4.
public static class BatmanRom
{
    static void Check(bool condition, string message)
    {
        if (!condition) throw new InvalidDataException(message);
    }
    public static string Hash(string path)
    {
        using (var h = SHA256.Create())
        using (var f = File.OpenRead(path))
            return BitConverter.ToString(h.ComputeHash(f)).Replace("-", "").ToLowerInvariant();
    }
    public static string Convert(string s24, string mapPath, string output, bool checkAlignment)
    {
        byte[] rom = new byte[4194304];
        bool[] seen = new bool[rom.Length];
        for (int i = 0; i < rom.Length; ++i) rom[i] = 255;
        int records = 0;
        foreach (string line in File.ReadLines(s24))
        {
            if (!line.StartsWith("S1") && !line.StartsWith("S2") && !line.StartsWith("S3")) continue;
            int n = line[1] - '1' + 2;
            Check(line.Length % 2 == 0 && line.Length >= 2 + 2 * (n + 2), "Malformed S-record");
            byte[] raw = new byte[(line.Length - 2) / 2];
            int sum = 0;
            for (int i = 0; i < raw.Length; ++i)
            {
                raw[i] = System.Convert.ToByte(line.Substring(2 + 2 * i, 2), 16);
                sum += raw[i];
            }
            Check(raw.Length == raw[0] + 1 && (sum & 255) == 255, "S-record length/checksum failure");
            int at = 0;
            for (int i = 1; i <= n; ++i) at = checked((at << 8) | raw[i]);
            int length = raw.Length - n - 2;
            if (length == 0) continue;
            int offset;
            if (at >= 0x200000 && (long)at + length <= 0x400000) offset = at - 0x200000;
            else if (at >= 0x800000 && (long)at + length <= 0xa00000) offset = 0x200000 + at - 0x800000;
            else throw new InvalidDataException("S-record outside cartridge windows: " + at.ToString("X"));
            for (int i = 0; i < length; ++i)
            {
                Check(!seen[offset + i], "Overlapping cartridge load images");
                seen[offset + i] = true;
                rom[offset + i] = raw[n + 1 + i];
            }
            ++records;
        }
        Check(records > 0 && Encoding.ASCII.GetString(rom, 36, 12) == "BATMAN MOVIE", "Missing/invalid Batman cartridge header");
        for (int i = 0x1f0000; i < 0x200000; ++i)
            Check(!seen[i] && rom[i] == 255, "Image overlaps save/BIOS flash sectors");
        string map = File.ReadAllText(mapPath);
        var values = new Dictionary<string, int>();
        foreach (Match m in Regex.Matches(map, @"(__[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})"))
            values[m.Groups[1].Value] = System.Convert.ToInt32(m.Groups[2].Value, 16);
        int ramEnd = values["__DataRAM_START"] + values["__DataROM_END"] - values["__DataROM_START"];
        int ramLimit = values.ContainsKey("__GraphicsROM_START") ? 0x6b60 : 0x6c00;
        Check(values["__Bss_END"] <= ramLimit && ramEnd <= ramLimit, "RAM overlaps runtime code or BIOS workspace");
        if (checkAlignment)
        {
            Match m = Regex.Match(map, @"_stage_work\s+([0-9A-F]{4,6})\s+f_area");
            Check(m.Success && System.Convert.ToInt32(m.Groups[1].Value, 16) % 2 == 0, "Unaligned stage_work");
        }
        string[] names = { "Pcm", "Graphics", "Clear", "FastAxis", "FastCat", "FastVeh", "PlatformScan", "NativeKernel", "NativeRoad" };
        int[] limits = { 496, 160, 64, 448, 448, 448, 4008, 400, 676 };
        for (int i = 0; i < names.Length; ++i)
        {
            string start = "__" + names[i] + "ROM_START", end = "__" + names[i] + "ROM_END";
            if (!values.ContainsKey(start))
            {
                Check(i < 6, "Missing required kernel: " + names[i]);
                continue;
            }
            int size = values[end] - values[start];
            Check(size > 0 && size <= limits[i], names[i] + " exceeds its RAM window");
        }
        string[] sections = { "PCM_NATIVE", "FAST_AXIS", "FAST_CAT", "FAST_VEH", "GRAPHICS_DIFF", "RAM_CLEAR" };
        int[] sectionLimits = { 496, 448, 448, 448, 160, 64 };
        for (int i = 0; i < sections.Length; ++i)
        {
            MatchCollection sizes = Regex.Matches(map, @"\b" + sections[i] + @"\s+CODE\s+[0-9A-F]+\s+([0-9A-F]+)\s+" + sections[i] + @"\(");
            if (sizes.Count != 0)
                Check(sizes.Count == 1 && System.Convert.ToInt32(sizes[0].Groups[1].Value, 16) <= sectionLimits[i], sections[i] + " exceeds reserved RAM");
        }
        Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(output)));
        File.WriteAllBytes(output, rom);
        return Hash(output);
    }
}
