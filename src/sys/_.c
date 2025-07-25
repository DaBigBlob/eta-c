#ifndef SRC_SYS___C
#define SRC_SYS___C

/* final preparation for direct usage by program */

#include "./target/_.c" // IWYU pragma: keep

// declare right symbol name for bein called by __asm__ ("__sys_extry")
uint sys_main(uint argc, list(string) argv) __asm__ ("__sys_main");

#ifndef STDIN_FD
    #error "target requirements not met: STDIN_FD undefined"
#endif // STDIN_FD
#ifndef STDOUT_FD
    #error "target requirements not met: STDOUT_FD undefined"
#endif // STDOUT_FD
#ifndef STDERR_FD
    #error "target requirements not met: STDERR_FD undefined"
#endif // STDERR_FD

#ifndef NEWLINE
    #define NEWLINE "\n"
#endif // NEWLINE

#define nl NEWLINE

#endif //SRC_SYS___C
