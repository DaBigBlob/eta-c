#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

#include "../../lib/prelude.c"

status _target_unpack_args(uint *ret_argc_p, list(string) * ret_argv_p, string *ret_err_p);
status _target_exit(uint code);

status _target_openf(const string path, uint oFlags, memp ret_fd);

status _target_readf(const memp fd, memp ret_mut_buff,
                   const memsz nbytes_towrite, memsz ret_nbytes_written);
status _target_writef();
status _target_cosef();

#endif // SRC_SYS_TARGETS__REQUIREMENTS_C
