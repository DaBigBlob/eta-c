#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

// _requirements -> targets -> target_guards -> internal use

#include "../../lib/prelude.c"

deft(zerot, _target_unpack_args,
    struct {uint argc_p; list(string) argv_p;},
    const string
)
defn(_target_unpack_args);

deft(uint, __target_exit, zerot, zerot)
defn(__target_exit);

deft(struct {const string path; uint oflags;}, _target_openf, memp, const string)
defn(_target_openf);

void _target_readf(
    const memp fd, memp ret_mut_buff, const memsz nbytes_toread, memsz ret_nbytes_written
);
void _target_writef();
void _target_cosef();

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
