
void sys_entry(void) __asm__ ("__sys_entry");

__attribute__((naked)) void sys_entry(void) {
    __asm__ __volatile__ (
        // "bl    __sys_main\n"
        // x0 <- sys_main’s return val
        "mov   x0, #69\n"

        // exit(x0)
        "mov   x16, #1\n"               // SYS_exit low bits
        "movk  x16, #0x2000, lsl #16\n" // high bits for 0x2000001
        "svc   #0x80\n"                 // syscall
    );
}
