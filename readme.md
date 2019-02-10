# PPCD
PPCD is very accurate disassembler for PowerPC processors made by org.
So far it supports the following ISA :
- PowerPc-32 (Generic)
- PowerPc-64 (Generic)
- Gekko (GameCube)
- Broadway/PowerPC 750CL (Wii)

## Configuration
The target architecture should be defined before compilation in ppcd.cpp.

## Compilation
This tool seriously needed a makefile, so I wrote a very basic one.
Run "make" to compile, "make clean" to remove object files and binaries.

## Code style and warning
Althought this tool was written by org, and as he said in ppcd.cpp :
"Look away, code is messed :)". PPCD makes heavy use of deprecated
functions, non-standard C++ features and triggers hundreds of warnings
of all kind while compiled. Do not remove the c++03 and permissive flags 
in the makefile, or it won't compile.

## Usage
./ppcd <binary file>
PPCD outputs on stdout.

## TODO
- Clean-up
- Add output options
- File format auto-detection
- Support file output
- Allow the user to specify the target architecture as a parameter
  rather than in ppcd.cpp

## Changelog
- 0.01 Initial release. Generic 32/64-bit ISA is implemented and extensively tested.
- 0.02 Added support for Gekko.
- 0.03 Fixed some typos.
- 0.04 Forked ogamespec's repo / Made the code valid outside of an IDE.
