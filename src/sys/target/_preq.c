#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

// _preq -> targets -> target_guards -> sys__guards -> internal use

#include "../../lib/prelude.c"

/* entry of the program */
void sys_entry(void) __asm__ ("__sys_entry");

/* syscall, etc */

deft(
    _target_openf,
    struct {string path; uint oflags;},
    struct {const memp fd;},
    string
)
static inline defn(_target_openf);

deft(
    _target_readf,
    struct {memp fd; memp wbuff; memsz nbytes_to_read;},
    struct {memsz nbytes_read;},
    string
)
static inline defn(_target_readf);

deft(
    _target_writef,
    struct {memp fd; memp rbuff; memsz nbytes_to_write;},
    struct {memsz nbytes_written;},
    string
)
static inline defn(_target_writef);

deft(
    _target_cosef,
    struct {memp fd;},
    zerot,
    string
)
static inline defn(_target_cosef);

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
