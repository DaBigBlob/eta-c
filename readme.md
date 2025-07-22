# C implementation of Eta Language
Eta is a dependently typed, highly parallel, functional style programming language and theorem prover with higher order metaprogramming.

## dependencies
### development-time
- `printf` (writing to files (including stdout))
- `tr` (find and replace)
- `mkdir` (recursive directory creation)
- `pwd` (full path fetching)
- `make` (a GNU Make implementation)
- `sh` (any POSIX compatible shell)
- `zig cc` / `clang` / `gcc` (a GCC compatible C compiler)

### build-time
- `printf` (writing to files (including stdout))
- `mkdir` (recursive directory creation)
- `make` (a GNU Make implementation)
- `zig cc` / `clang` / `gcc` (a GCC compatible C compiler)

### run-time
- target kernel

## development
- use `newcfile` shell script to create new files
- no dependencies external to this repository allowed
- must not depend on system secific code (expeption: code in src/sys)
    - this includes a system's libc
- all submitted code must abide by the lisence of this repository

## building
```bash
make build  # to build (alias: make b)
make clean  # to remove all build artifacts (alias: make c)
make run    # to rebuild and try run the executable if native (alias: make r)
```
### C compiler
`make build` uses `zig cc` as the C compiler.  
You may select other compilers in your path (e.g. `gcc`) like so: `CC=gcc make build`  

### cross compiling
You may set `CC` with any target options your compiler supports (e.g. `x86_64-windows-gnu`) like so: `zig cc -static -target x86_64-windows-gnu`  
I recommend `zig cc` for cross compiling to ordinary targets under LLVM.  

