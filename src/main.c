#ifndef SRC_MAIN_C
#define SRC_MAIN_C

#include "./lib/prelude.c"

uint sys_main(uint argc, list(string) argv) {
    
    // hey clang, how about you shut the fuck up?
    if (argc) if (argv) {}

    return 0;
}
 
#endif //SRC_MAIN_C
