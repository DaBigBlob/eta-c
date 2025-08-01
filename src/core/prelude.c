#ifndef SRC_CORE_PRELUDE_C
#define SRC_CORE_PRELUDE_C

/**
This file defines conventions so that other files can talk to each other.
It also defines semantic artifacts (e.g. list) that cause no runtime cost
but only exist for semantic clarity. 
*/

#define list(__type_t) __type_t*

/// should be tied to sizeof
typedef char byte;

typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

/// mem pointer
/// not void* to make pointer arithmetic easier
typedef byte* memp;
/// mem sized
typedef ulong memsz;

/// pointer to bytes list
typedef list(byte) string;

/// simple bool
typedef enum {
    true = 1,
    false = !true
} bool; // maybe even "__attribute__((__packed__)) bool"?;

/// empty data
/// CC -Wno-gnu-empty-struct
typedef struct {} zerot;

/// monadic struct as function type def created with "defn"
/// wants to preserve referencial transparency
/// all side-effect-able object reference should be passed though this struct
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

/// naming struct for use with "fn" functions
#define fnd(name) name##_data

/// for defining function body with type signature defined using "defn"
#define defn(name)\
void name##_fn(name##_data *var)

/// naming functions defined using "deft" and "defn"
#define fn(name) name##_fn

/// convenient macro for const str err return from "fn" functions
#define def_errstr(fname, name)\
const string ERRSTR_##name##fname = #fname" ERROR: "

/// expose symbols because default CC -fvisibility=hidden
#define expose(name, as_name)\
void name(void) __asm__ (#as_name);

/// reminder to use the following to make clangd shutup
// IWYU pragma: keep

#endif //SRC_CORE_PRELUDE_C
