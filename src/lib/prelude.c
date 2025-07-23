#ifndef SRC_LIB_PRELUDE_C
#define SRC_LIB_PRELUDE_C

typedef void* memp;

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef char byte;

typedef enum _tag_bool {
    true = 1,
    false = !true
} __attribute__((__packed__)) bool;
 
#endif //SRC_LIB_PRELUDE_C
