#ifndef SRC_MAIN__OUT_C
#define SRC_MAIN__OUT_C

/*
Exporting symbols implemented in src/main.
*/

#include "./main.c" // IWYU pragma: keep

uint sys_main(uint argc, list(string) argv) __asm__ ("__sys_main");

#endif //SRC_MAIN__OUT_C
