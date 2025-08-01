#ifndef SRC_CORE_STRING_C
#define SRC_CORE_STRING_C

/*
Utility functions to deal with (byte) strings.
*/

#include "./prelude.c"

/// returns length of buffer (excluding byte delimitor)
#define _def_byte_delimit_sizeof_buff(delim, buff) {\
    for (memp b = buff;; b++) if (*b == delim) return b - buff;\
}

/// length of arbitary byte delimited string
inline memsz
sizeof_delim_buff(byte delim, const memp buff)
_def_byte_delimit_sizeof_buff(delim, buff)

/// length of \0 delimited string
inline memsz
sizeof_buff(const memp buff)
_def_byte_delimit_sizeof_buff('\0', buff)

#endif //SRC_CORE_STRING_C
