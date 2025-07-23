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

typedef struct {} zerot;

#define deft(in_t, name, out_ok_t, out_err_t)\
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


/* examples */
// deft(int, bb, int, zerot)
// defn(bb) {
//     int a = var->in;
//     var->out.isok = true;
//     var->out.unwrap.ok = 2;
// }

// void aa() {
//     bb_data nu = {
//         .in = 9
//     };
//     bb_fn(&nu);
//     if (nu.out.isok) nu.in = nu.out.unwrap.ok;
// }

#endif // SRC_LIB_PRELUDE_C
