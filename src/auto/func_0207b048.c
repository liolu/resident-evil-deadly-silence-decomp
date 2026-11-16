/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02116dac(s32, s32);
s8 func_02117de0(void);
s32 func_02117e20(u8);
s32 func_02117e68(s16);
s32 func_02117eb0(s32, s32);

void func_0207b048(u8 *arg0) {
    s32 buf[2];
    s32 i;
    s32 r8;

    i                      = 0;
    *(s32 *) (arg0 + 0x18) = i;
    do {
        r8 = func_02117e20(arg0[i + 4]);
        func_02116dac(r8, func_02117eb0(func_02117e68(*(s16 *) (arg0 + 2)), *(s32 *) (arg0 + i * 4 + 8)));
        ((u8 *) buf)[i] = func_02117de0();
        *(s32 *) (arg0 + 0x18) |= ((u8 *) buf)[i] << ((3 - i) * 8);
        i++;
    } while (i < 4);
}
