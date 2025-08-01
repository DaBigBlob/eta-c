#ifndef SRC_MAIN___C
#define SRC_MAIN___C

/*
Entry for compiler.
*/

#include "../core/prelude.c" // IWYU pragma: keep

uint sys_main(uint argc, list(string) argv) __asm__ ("__sys_main");

#endif //SRC_MAIN___C
