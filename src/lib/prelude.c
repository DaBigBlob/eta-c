#ifndef SRC_LIB_PRELUDE_C
#define SRC_LIB_PRELUDE_C
/* mostly for semantic consistency */

#define list(__type_t) __type_t*

typedef char byte; // should be tied to sizeof

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef byte* memp; // mem pointer // not void* to make *arithmetic easier
typedef ulong memsz; // mem sized

typedef list(char) string;

typedef enum _tag_bool {
    true = 1,
    false = !true
} bool; // maybe even? __attribute__((__packed__)) bool;
 
#endif //SRC_LIB_PRELUDE_C
