/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_0207b0cc(void *, s32);
extern s32 func_02117970(s32, s32);
extern s32 func_02117e20(u8);
extern s32 func_02117e68(s8);
extern s32 func_0211809c(s32, s32);

void func_0207b0f0(void *arg0) {
    u8 buf[4];
    s32 i;
    s32 a;
    s32 b;
    s32 r;

    func_0207b0cc((u8 *) arg0 + 4, *(s32 *) (*(u8 **) ((u8 *) arg0 + 0x1C) + 4));
    func_0207b0cc(buf, *(s32 *) (*(u8 **) ((u8 *) arg0 + 0x1C) + 8));
    i = 0;
    do {
        a                              = func_02117e20(buf[i]);
        b                              = func_02117e20(((u8 *) arg0)[i + 4]);
        r                              = func_0211809c(a, b);
        a                              = r;
        b                              = func_02117e68(*(s8 *) *(u8 **) ((u8 *) arg0 + 0x1C));
        ((s32 *) ((u8 *) arg0 + 8))[i] = func_02117970(a, b);
        i                              = i + 1;
    } while (i < 4);
}
