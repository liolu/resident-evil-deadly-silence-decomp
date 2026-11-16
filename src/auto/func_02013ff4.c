/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02137300;

void func_02091a5c(s32 a, void *b);
void func_02116dac(s32 a, s32 b);
s8 func_02117de0(void);
s32 func_02117e20(u8 a);
s32 func_02117e68(s32 a);
s32 func_02117eb0(s32 a, s32 b);

s32 func_02013ff4(s32 arg0, s32 arg1) {
    u8 sp0[4];
    s32 r7;
    s32 r5;

    func_02091a5c(arg0, sp0);
    r7 = 1;
    do {
        r5 = func_02117e20(sp0[r7]);
        func_02116dac(r5, func_02117eb0(func_02117e68(arg1), *(s32 *) ((u8 *) &data_02137300 + r7 * 4 - 4)));
        sp0[r7] = func_02117de0();
        r7 += 1;
    } while (r7 < 4);
    return ((s32) sp0[1] << 16) | ((s32) sp0[2] << 8) | sp0[3];
}
