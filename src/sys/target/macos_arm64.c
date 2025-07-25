#ifndef SRC_SYS_TARGETS_MACOS_ARM64_C
#define SRC_SYS_TARGETS_MACOS_ARM64_C

#include "./_preq.c"

__attribute__((naked)) void sys_entry(void) {
    __asm__ __volatile__(
        "mov    x2, sp\n"        // x2 = original SP
        "ldr    x0, [x2]\n"      // x0 = argc
        "add    x1, x2, #8\n"    // x1 = argv (char **)
        "bl     __sys_main\n"    // call main(argc, argv)
        // Upon return, x0 holds main's return value
        "mov    x16, #1\n"       // syscall number: exit (low bits)
        "movk   x16, #0x2000, lsl #16\n" // complete to 0x2000001
        "svc    #0x80\n"        // trap into kernel
    );
}

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
        : "r" (callno), "r" (a1), "r" (a2), "r" (a3)
        : "memory", "x0", "x1", "x2", "x16"
    );
    return _ret;
}

#define STDIN_FD (memp)(long)0
#define STDOUT_FD (memp)(long)1
#define STDERR_FD (memp)(long)2

static inline defn(_target_writef) {
    memp _ret = ___internal_macos_arm64_syscall3(
        (memp)0x2000004,
        (memp)(long)var->in.fd,
        var->in.rbuff,
        (memp)var->in.nbytes_to_write
    );
    if ((long)_ret < 0) {
        var->out.isok = false;
        // TODO: define all errors as const string
    } else {
        var->out.isok = true;
        var->out.unwrap.ok.nbytes_written = (long)_ret;
    }
}

#endif // SRC_SYS_TARGETS_MACOS_ARM64_C
