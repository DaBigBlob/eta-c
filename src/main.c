#ifndef SRC_MAIN_C
#define SRC_MAIN_C

#include "./lib/prelude.c"
#include "./lib/bytes.c"
#include "./sys/_.c" // IWYU pragma: keep

enum sys_main_EXITCODE {
    EXIT_OK = 0,
    EXIT_STDOUT_write_failed = 1
};

uint sys_main(uint argc, list(string) argv) {

    if (argc < 2) return 2; // TODO: better error handeling

    _target_writef_data wdata = {
        .in = {
            .fd = STDOUT_FD,
            .rbuff = argv[1],
            .nbytes_to_write = sizeof_buff(wdata.in.rbuff)
        }
    };
    _target_writef_fn(&wdata);
    if (!wdata.out.isok) return EXIT_STDOUT_write_failed;

    return EXIT_OK;
}
 
#endif //SRC_MAIN_C
