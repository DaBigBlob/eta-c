
CC = zig cc -static
CFLAGS = -nostdinc -nostdlib -O3 -Wall -Wextra -Wfatal-errors -ffreestanding -fomit-frame-pointer -fno-plt -nodefaultlibs -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-stack-protector -fno-builtin -std=c11 -pedantic -Wl,-e,__sys_entry -g0 -fno-exceptions -Wa,--noexecstack -fno-ident -Wno-gnu-empty-struct -fvisibility=hidden


ENTRY = src/main.c
BIN = bin/
NAME = eta

_PRINTER = printf
_MKDIR = mkdir -p

build: ${ENTRY}
	@${_MKDIR} ${BIN}
	${CC} ${ENTRY} ${BFLAGS} ${CFLAGS} -o ${BIN}${NAME}
	@${_PRINTER} "built to: ${BIN}${NAME}\n"

clean: ${BIN}
	rm -rf ${BIN}

run: build
	@${_PRINTER} "running: ${BIN}${NAME}\n\n" 
	@${BIN}${NAME} ${RA}

# aliases
b: build
c: clean
r: run