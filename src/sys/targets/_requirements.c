#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

// _requirements -> targets -> target_guards -> internal use

#include "../../lib/prelude.c"

void _target_unpack_args(uint *ret_argc_p, list(string) * ret_argv_p, string *ret_err_p);
void _target_exit(uint code);

void _target_openf(const string path, uint oFlags, memp ret_fd);

void _target_readf(const memp fd, memp ret_mut_buff,
                   const memsz nbytes_toread, memsz ret_nbytes_written);
void _target_writef();
void _target_cosef();

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
