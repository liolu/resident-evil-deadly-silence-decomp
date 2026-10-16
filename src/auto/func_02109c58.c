/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

extern unsigned short data_0215a828[];
extern int data_0215a840[];
struct V4 {
    unsigned short a, b, c, d;
};

/* func_0214e334 from https://github.com/RonyxDumb/mkds src/arm9/0214e334_func_0214e334.c (license: none), reused by
 * tools/donor_match.py */
void func_02109c58(struct V4 *r0, struct V4 *r1) {
    int *p;
    int t;
    if (data_0215a828[0x18] == 0) {
        *r0 = *r1;
        return;
    }
    p     = data_0215a840;
    r0->c = r1->c;
    r0->d = r1->d;
    if (r1->c == 0) {
        r0->a = 0;
        r0->b = 0;
        return;
    }
    r0->a = (int) (((long long) p[2] * ((long long) (r1->a << 2) - (long long) p[0])) >> 22);
    t     = (short) r0->a;
    if (t < 0) {
        r0->a = 0;
    } else if (t > 0xff) {
        r0->a = 0xff;
    }
    r0->b = (int) (((long long) p[5] * ((long long) (r1->b << 2) - (long long) p[3])) >> 22);
    t     = (short) r0->b;
    if (t < 0) {
        r0->b = 0;
        return;
    }
    if (t > 0xbf) {
        r0->b = 0xbf;
    }
}
