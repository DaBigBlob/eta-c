#ifndef SRC_SYS_TARGETS_MACOS_ARM64_C
#define SRC_SYS_TARGETS_MACOS_ARM64_C

#include "./_requirements.c"

static inline defn(_target_unpack_args){
    //TODO
    // shutup clang
    if (var) {}
}

static inline defn(_target_exit){
    __asm__ __volatile__ (
        // x0 = code (argument), x16 = syscall number (0x2000001)
        "mov x0, %0\n"
        "mov x16, #1\n"
        "movk x16, #0x2000, lsl #16\n"
        "svc #0x80\n"
        :
        : "r"((long)var->in)
        : "x0", "x16", "memory"
    );
    var->out.isok = true; // actually unreachable
}

#endif // SRC_SYS_TARGETS_MACOS_ARM64_C
