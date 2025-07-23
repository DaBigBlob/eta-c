#ifndef SRC_LIB_PRELUDE_C
#define SRC_LIB_PRELUDE_C
/* mostly for semantic consistency */

#define list(__type_t) __type_t *

typedef char byte; // should be tied to sizeof

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef byte *memp;  // mem pointer // not void* to make *arithmetic easier
typedef ulong memsz; // mem sized

typedef list(char) string;

typedef enum _tag_bool {
    true = 1,
    false = !true
} bool; // maybe even __attribute__((__packed__)) bool?;

// graceful error handeling
#define def_result(name, etc)\
typedef struct __result##name {\
    bool ok;\
    etc;\
} result##name

def_result(, ); // result
const result RESOK = {.ok = true};
const result RESERR = {.ok = false};

def_result(_str, string more); // result_str

// result complient functions
#define defn(name, rettype, ivar)\
    typedef struct __result##name {\
        bool ok;\
        rettype;\
    } result##name;\
    result##name *fn##name(result##name *ivar)

/* example */
// _defn(_b, result_str, s) {
//     s->ok = true;
//     s->more = 0;
//     return s;
// }
// void a() {
//     result_str nigma;
//     bool lol = fn_b(&nigma)->ok;
// }

#endif // SRC_LIB_PRELUDE_C
