#ifndef SRC_MAIN_C
#define SRC_MAIN_C

#include "./lib/prelude.c"
#include "./lib/bytes.c"
#include "./sys/_.c" // IWYU pragma: keep

enum sys_main_EXITCODE {
    EXIT_OK = 0,
    EXIT_STDOUT_write_failed = 1,
    EXIT_STDERR_write_failed = 2,
    EXIT_error_set_in_STDERR = 3
};

uint sys_main(uint argc, list(string) argv) {
    _target_writef_data owd = {.in.fd = STDOUT_FD};
    _target_writef_data ewd = {.in.fd = STDERR_FD};

    if (argc != 2) {
        ewd.in.rbuff = "need exactly 1 argument" nl "\0";
        ewd.in.nbytes_to_write = sizeof_buff(ewd.in.rbuff);
        _target_writef_fn(&ewd);
        if (ewd.out.isok) return EXIT_error_set_in_STDERR;
        else return EXIT_STDERR_write_failed;
    }

    owd.in.rbuff = argv[1];
    owd.in.nbytes_to_write = sizeof_buff(owd.in.rbuff);
    _target_writef_fn(&owd);
    if (!owd.out.isok) return EXIT_STDOUT_write_failed;

    return EXIT_OK;
}
 
#endif //SRC_MAIN_C
