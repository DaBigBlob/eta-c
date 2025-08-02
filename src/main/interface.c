#ifndef SRC_MAIN_INTERFACE_C
#define SRC_MAIN_INTERFACE_C

/*
Interface of self to external.
This file should not include any internal implementation.
*/

#include "../lib/prelude.c"

uint sys_main(uint argc, list(string) argv) __asm__ ("__sys_main");

#endif //SRC_MAIN_INTERFACE_C
