#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

// _requirements -> targets -> target_guards -> internal use

#include "../../lib/prelude.c"

deft(
    zerot,
    _target_unpack_args,
    struct {uint argc_p; list(string) argv_p;},
    zerot
)
defn(_target_unpack_args);

deft(
    uint,
    _target_exit,
    zerot,
    zerot
)
defn(_target_exit);

deft(
    struct {const string path; uint oflags;},
    _target_openf,
    struct {const memp fd;},
    const string
)
defn(_target_openf);

deft(
    struct {const memp fd; memp wbuff; const memsz nbytes_to_read;},
    _target_readf,
    struct {const memsz nbytes_read;},
    const string
)
defn(_target_readf);

deft(
    struct {memp fd; const memp rbuff; const memsz nbytes_to_write;},
    _target_writef,
    struct {const memsz nbytes_written;},
    const string
)
defn(_target_writef);

deft(
    struct {const memp fd;},
    _target_cosef,
    zerot,
    const string
)
defn(_target_cosef);

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
