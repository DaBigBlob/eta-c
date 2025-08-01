#ifndef SRC_CORE_PRELUDE_C
#define SRC_CORE_PRELUDE_C

/**
This file defines conventions so that other files can talk to each other.
It also defines semantic artifacts (e.g. list) that cause no runtime cost
but only exist for semantic clarity. 
*/

#define list(__type_t) __type_t*

typedef char byte; // should be tied to sizeof

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef byte* memp;  // mem pointer // not void* to make *arithmetic easier
typedef ulong memsz; // mem sized

typedef list(char) string;

typedef enum _tag_bool {
    true = 1,
    false = !true
} bool; // maybe even __attribute__((__packed__)) bool?;

typedef struct {} zerot; // add -Wno-gnu-empty-struct

#define deft(name, in_t, out_ok_t, out_err_t)\
typedef union {\
    struct {\
        union {\
            out_ok_t ok;\
            out_err_t err;\
        } unwrap;\
        bool isok;\
    } out;\
    in_t in;\
} name##_data;

#define defn(name)\
void name##_fn(name##_data *var)

#define def_errstr(fname, name) const string ERRSTR_##name##fname = #fname" ERROR: "


#endif //SRC_CORE_PRELUDE_C
