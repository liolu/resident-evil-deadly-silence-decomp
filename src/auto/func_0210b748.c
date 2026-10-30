/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* PM_Initialize from https://github.com/RonyxDumb/mkds src/arm9/021500a0_PM_Initialize.c (license: none), reused by
 * tools/donor_match.py */
extern unsigned short data_0215a880;
extern int data_0215a898[2];
extern short data_0215a8bc;
extern char data_0215a8a8;
extern int data_0215a890;
extern void func_0210b65c(void);
extern void func_02107b0c(void);
extern int func_02107cf0(int bit, int word);
extern void func_02107d18(int a, void *b);
extern void func_0210461c(char *p);
#pragma opt_strength_reduction off
void func_0210b748(void) {
    int i;
    if (data_0215a880 != 0) {
        return;
    }
    data_0215a880    = 1;
    data_0215a898[0] = 0;
    data_0215a898[1] = 0;
    func_02107b0c();
    while (func_02107cf0(8, 1) == 0)
        ;
    func_02107d18(8, (void *) func_0210b65c);
    for (i = 0; i < 4; i++) {
        *(short *) ((char *) &data_0215a8bc + (i << 3)) = 0;
    }
    func_0210461c(&data_0215a8a8);
    data_0215a890 = *(int *) 0x27ffc3c;
}
