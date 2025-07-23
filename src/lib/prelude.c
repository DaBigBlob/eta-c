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
#define _def_result(name, etc)                                                 \
  typedef struct __result##name {                                              \
    bool ok;                                                                   \
    etc;                                                                       \
  } result##name

_def_result(, ); // result
const result RESOK = {.ok = true};
const result RESERR = {.ok = false};

_def_result(_str, string more); // result_str

// result complient functions
#define _defn(name, _ret_t, ivar) _ret_t *fn_##name(_ret_t *ivar)

/* example */
// _defn(b, result_str, s) {
//     s->ok = true;
//     s->more = 0;
//     return s;
// }
// void a() {
//     result_str nigma;
//     bool lol = fn_b(&nigma)->ok;
// }

#endif // SRC_LIB_PRELUDE_C
