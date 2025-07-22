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

## building
```bash
make build  # to build
make clean  # to remove all build artifacts
make run    # to rebuild and try run the executable if native
```
### C compiler
`make build` uses `zig cc` as the C compiler.  
You may select other compilers in your path (for e.g. `gcc`) like so: `CC=gcc make build`