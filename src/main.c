#ifdef SRC_MAIN_C
    #error "src/main.c is entry point and should not be included by anything"
#else
#define SRC_MAIN_C

#include "./lib/prelude.c"
#include "./lib/bytes.c"
#include "./sys/_.c"

enum sys_main_EXITCODE {
    EXIT_OK = 0,
    EXIT_STDOUT_write_failed = 1,
    EXIT_STDERR_write_failed = 2,
    EXIT_msg_set_in_STDERR = 3
};

uint sys_main(uint argc, list(string) argv) {
    _target_writef_data wd;

    if (argc != 2) {
        wd.in.fd = STDERR_FD;
        wd.in.rbuff = "need exactly 1 argument" nl "\0";
        wd.in.nbytes_to_write = sizeof_buff(wd.in.rbuff);
        _target_writef_fn(&wd);
        if (wd.out.isok) return EXIT_msg_set_in_STDERR;
        return EXIT_STDERR_write_failed;
    }

    wd.in.fd = STDOUT_FD;
    wd.in.rbuff = argv[1];
    wd.in.nbytes_to_write = sizeof_buff(wd.in.rbuff);
    _target_writef_fn(&wd);
    if (!wd.out.isok) return EXIT_STDOUT_write_failed;

    return EXIT_OK;
}
 
#endif //SRC_MAIN_C
