#ifndef SRC_SYS_TARGETS_MACOS_ARM64_C
#define SRC_SYS_TARGETS_MACOS_ARM64_C

#include "./_requirements.c"

static inline memp ___internal_macos_arm64_syscall3(memp callno, memp a1, memp a2, memp a3) {
    void* _ret;
    __asm__ __volatile__ (
        "mov x16, %1\n"
        "mov x0, %2\n"
        "mov x1, %3\n"
        "mov x2, %4\n"
        "svc #0x80\n"
        "mov %0, x0\n"
        : "=r" (_ret)
        : "r" (0x2000000+callno), "r" (a1), "r" (a2), "r" (a3)
        : "memory", "x0", "x1", "x2", "x16"
    );
    return _ret;
}

static inline defn(_target_unpack_args){
    //TODO
    // shutup clang
    if (var) {}
}

const string ERR_EXIST = "_target_exit: could not exit program";
static inline defn(_target_exit){
    ___internal_macos_arm64_syscall3((memp)1, (memp)(long)var->in, 0, 0);
    var->out.isok = false; // actually unreachable so false i.e. something went wrong
    var->out.unwrap.err = ERR_EXIST;
}

#endif // SRC_SYS_TARGETS_MACOS_ARM64_C
