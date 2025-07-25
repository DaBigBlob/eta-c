#ifndef SRC_SYS___C
#define SRC_SYS___C

#include "./target/_.c" // IWYU pragma: keep

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
