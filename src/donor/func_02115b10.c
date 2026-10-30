/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* __timesdec from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/ansi_fp.c (license: none), reused by
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
extern void func_02115dec(decimal *d, int digits);
extern void func_02115b10(decimal *result, const decimal *x, const decimal *y);
void func_02115dec(decimal *d, int digits);
void func_02115b10(decimal *result, const decimal *x, const decimal *y) {
    unsigned long accumulator = 0;
    unsigned char mantissa[32 * 2];
    int i             = x->sig.length + y->sig.length - 1;
    unsigned char *ip = mantissa + i + 1;
    unsigned char *ep = ip;

    result->sgn = 0;

    for (; i > 0; i--) {
        int k = y->sig.length - 1;
        int j = i - k - 1;
        int l;
        int t;
        const unsigned char *jp;
        const unsigned char *kp;

        if (j < 0) {
            j = 0;
            k = i - 1;
        }

        jp = x->sig.text + j;
        kp = y->sig.text + k;
        l  = k + 1;
        t  = x->sig.length - j;

        if (l > t) {
            l = t;
        }

        for (; l > 0; l--, jp++, kp--) {
            accumulator += *jp * *kp;
        }

        *--ip = (unsigned char) (accumulator % 10);
        accumulator /= 10;
    }

    result->exp = (short) (x->exp + y->exp);

    if (accumulator > 0) {
        *--ip = (unsigned char) accumulator;
        result->exp++;
    }

    for (i = 0; i < 32 && ip < ep; i++, ip++) {
        result->sig.text[i] = *ip;
    }

    result->sig.length = (unsigned char) i;

    if (ip < ep && *ip >= 5) {
        if (*ip == 5) {
            unsigned char *jp = ip + 1;
            for (; jp < ep; jp++) {
                if (*jp != 0) {
                    goto round;
                }
            }
            if ((*(ip - 1) & 1) == 0) {
                return;
            }
        }
    round:
        func_02115dec(result, result->sig.length);
    }
}
