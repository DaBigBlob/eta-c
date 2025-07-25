#ifndef SRC_SYS_TARGETS_MACOS_ARM64_C
#define SRC_SYS_TARGETS_MACOS_ARM64_C

#include "./_preq.c"

__attribute__((naked))
void sys_entry(void) {
    __asm__ __volatile__ (
        // done by dyld:
        //   x0 <- argc
        //   x1 <- argv (char **)
        // why is dyld needed?
        // because the brilliant folks at XNU wrote this garbage: https://github.com/apple-oss-distributions/xnu/blob/a325d9c4a84054e40bbe985afedcb50ab80993ea/bsd/kern/mach_loader.c#L844-L862

        // with args: x0, x1
        // call sys_main(argc, argv)
        "bl    __sys_main\n"
        // x0 <- sys_main’s return val

        // exit(x0)
        "mov   x16, #1\n"               // SYS_exit low bits
        "movk  x16, #0x2000, lsl #16\n" // high bits for 0x2000001
        "svc   #0x80\n"                 // syscall
    );
}

static inline memp ___internal_macos_arm64_syscall3(memp callno, memp a1, memp a2, memp a3) {
    void* _ret;
    __asm__ __volatile__ (
        "mov x16, %1\n"     // set syscall #
        "mov x0, %2\n"      // arg0
        "mov x1, %3\n"      // arg0
        "mov x2, %4\n"      // arg0
        "svc #0x80\n"       // syscall
        "mov %0, x0\n"      // get return val
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
        // TODO: define all errors using def_errstr(fname, name)
    } else {
        var->out.isok = true;
        var->out.unwrap.ok.nbytes_written = (long)_ret;
    }
}

#endif // SRC_SYS_TARGETS_MACOS_ARM64_C
