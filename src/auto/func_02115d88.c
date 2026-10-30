/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* __rounddec from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/ansi_fp.c (license: none), reused by
 * tools/donor_match.py */
typedef struct decimal {
    char sgn;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} decimal;
extern int func_02115e3c(const decimal *d, int digits);
extern void func_02115dec(decimal *d, int digits);
extern void func_02115d88(decimal *d, int digits);
int func_02115e3c(const decimal *d, int digits);
void func_02115dec(decimal *d, int digits);
void func_02115d88(decimal *d, int digits) {
    if (digits > 0 && digits < d->sig.length) {
        int round     = func_02115e3c(d, digits);
        d->sig.length = digits;
        if (round >= 0) {
            func_02115dec(d, digits);
        }
    }
}
