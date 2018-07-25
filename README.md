# RdRand

Windows .NET Framework Library to use Intel RdRand CPU instruction.  

RDRAND instruction is available in Ivy Bridge processors.  

It includes a sample implementation.  

NOTE: You will need the Visual C++ Redistributable installed.  

## Example
```cs
using SilverCard;

try
{
    var us = RdRand.Rand16(); // Random ushort
    var ui = RdRand.Rand32(); // Random uint
    var ul = RdRand.Rand64(); // Random ulong, only available when DLL is compiled for x64
}
catch (RandomGeneratorException ex)
{
    // If RDRAND instructions return false for 10 times, this exception will be throw.
}
```
