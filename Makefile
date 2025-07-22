
CC = zig cc -static
CFLAGS = -nostdinc -nostdlib -O3 -Wall -Wextra -Wfatal-errors -ffreestanding -fomit-frame-pointer -fno-plt -nodefaultlibs -fno-asynchronous-unwind-tables -fno-unwind-tables -fdata-sections -fno-stack-protector -fno-builtin -std=c11 -pedantic -Wno-strict-prototypes -Wl,-e,__sys_entry -g0 -fno-exceptions -fno-rtti -fno-ident -Wa,--noexecstack -fno-ident


ENTRY = src/sys/entry.c
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
	@${_PRINTER} "running: ${BIN}${NAME}\n" 
	${BIN}${NAME} ${TA}