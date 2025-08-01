# C implementation of Eta Language
Eta is a dependently typed, highly parallel, functional style programming language and theorem prover with higher order metaprogramming.

## dependencies
### run-time
- target kernel

### build-time
- `printf` (writing to files (including stdout))
- `mkdir` (recursive directory creation)
- `make` (a GNU Make implementation)
- `zig cc` / `clang` / `gcc` (a GCC compatible C compiler)

### development-time
- `printf` (writing to files (including stdout))
- `tr` (find and replace)
- `mkdir` (recursive directory creation)
- `pwd` (full path fetching)
- `make` (a GNU Make implementation)
- `sh` (any POSIX compatible shell)
- `zig cc` / `clang` / `gcc` (a GCC compatible C compiler)

These (other than the C compiler) can be compiled with [`cosmopolitan toolchain`](https://justine.lol/cosmopolitan/index.html) to polymorphic binaries and shipped for a portable build system.

## development
- use `newcfile` shell script to create new files
    - file names must be in snake-case
    - example: `./newcfile src/sys/targets/dead_badger_riscv64.c`
- 4 space indentation
- C11 (+ empty structs)
- no dependencies external to this repository allowed
- no internal use of floats allowed
- must not depend on system secific code (expeption: code in src/sys/targets)
    - this includes a system's libc
    - this includes code that depends on the C runtime
- all submitted code must abide by the lisence of this repository

## building
```bash
make build  # to build (alias: make b) (set BFLAGS to pass extra args to compiler)
make clean  # to remove all build artifacts (alias: make c)
make run    # to rebuild and try run the executable if native (alias: make r) (set RA to pass commandline args to binary)
```
### C compiler
`make build` uses `zig cc` as the C compiler by default.  
You may select other compilers in your path (e.g. `gcc`) like so: `make build CC=gcc`  

### cross compiling
You may set `CC` with any target options your compiler supports (e.g. `x86_64-windows-gnu`) like so:  
```bash
make build CC="zig cc -static -target x86_64-windows-gnu"
```  
I recommend [`zig cc`](https://zig.guide/working-with-c/zig-cc/) for cross compiling to ordinary targets under LLVM.  
NOTE: while compiling to darwin targets, `zig cc` links to `/usr/lib/libSystem.B.dylib`. but using darwin-native clang, links against anothing (ideal as this is supposed to be a standalone binary).  


For polymorphic binaries, I recommend [`cosmopolitan's C compiler`](https://justine.lol/cosmopolitan/index.html).

# HEAVY WIP