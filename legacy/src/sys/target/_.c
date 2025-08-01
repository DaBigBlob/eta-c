#ifndef SRC_SYS_TARGETS___C
#define SRC_SYS_TARGETS___C

/* the right target is to be selected here */

#ifdef __APPLE__
    #ifdef __aarch64__
        #include "./macos_arm64.c" // IWYU pragma: keep
    #endif // __aarch64__
    #ifdef __x86_64__
        // TODO: implement
    #endif // __x86_64__
#endif // __APPLE__

// TODO: rest if the ifdef chain for each triplet
 
#endif //SRC_SYS_TARGETS___C
