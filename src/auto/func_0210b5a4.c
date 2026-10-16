/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0214fefc from https://github.com/RonyxDumb/mkds src/arm9/0214fefc_func_0214fefc.c (license: none), reused by
 * tools/donor_match.py */
extern int func_0210b880(void);
extern void func_0210b0e4(int param);
extern void func_0210adb4(int a, int b, int c, int d);
extern volatile int data_0215a884;
extern int data_0215a888;
int func_0210b5a4(unsigned int a, unsigned int b) {
    volatile int *p;

    if (!func_0210b880()) {
        return 1;
    }
    data_0215a884 = 0;
    func_0210b0e4(0x3006000);
    p = &data_0215a884;
    while (!*p) {
    }
    *p            = 0;
    data_0215a888 = 0;
    func_0210adb4(0, 2, 0, 0);
    func_0210b0e4((a & 0xff) | 0x2006100);
    func_0210b0e4((b & 0xffff) | 0x1010000);
    return 0;
}
