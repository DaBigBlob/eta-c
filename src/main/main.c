#ifndef SRC_MAIN_MAIN_C
#define SRC_MAIN_MAIN_C

#include "./prelude.c" // IWYU pragma: keep

uint sys_main(uint argc, list(string) argv) __asm__ ("__sys_main");

#endif //SRC_MAIN_MAIN_C
