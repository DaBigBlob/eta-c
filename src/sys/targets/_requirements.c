#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

// _requirements -> targets -> target_guards -> _ -> internal use

#include "../../lib/prelude.c"

deft(
    _target_unpack_args,
    zerot,
    struct {uint argc; list(string) argv;},
    zerot
)
static inline defn(_target_unpack_args);

deft(
    _target_exit,
    uint,
    zerot,
    zerot
)
static inline defn(_target_exit);

deft(
    _target_openf,
    struct {const string path; uint oflags;},
    struct {const memp fd;},
    const string
)
static inline defn(_target_openf);

deft(
    _target_readf,
    struct {const memp fd; memp wbuff; const memsz nbytes_to_read;},
    struct {const memsz nbytes_read;},
    const string
)
static inline defn(_target_readf);

deft(
    _target_writef,
    struct {memp fd; const memp rbuff; const memsz nbytes_to_write;},
    struct {const memsz nbytes_written;},
    const string
)
static inline defn(_target_writef);

deft(
    _target_cosef,
    struct {const memp fd;},
    zerot,
    const string
)
static inline defn(_target_cosef);

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
