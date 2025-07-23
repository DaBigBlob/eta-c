#ifndef SRC_SYS_TARGETS__REQUIREMENTS_C
#define SRC_SYS_TARGETS__REQUIREMENTS_C

#include "../../lib/prelude.c"

void _target_unpack_args(uint *argc_p, char * **argv_p);
void _target_exit(uint code);

void _target_openf();
void _target_readf();
void _target_writef();
void _target_cosef();
 
#endif //SRC_SYS_TARGETS__REQUIREMENTS_C
