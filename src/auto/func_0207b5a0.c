#include "m2c.h"

void func_0207b5a0(u8 *arg0, s32 arg1) {
    volatile s32 *r3;
    u8 *r0;
    s32 r2;
    s32 r1;

    r3    = *(s32 **) (arg0 + 0xC0);
    r3[3] = arg1;
    r0    = *(u8 **) arg0;
    r2    = *(s32 *) (r0 + 0x38);
    r1    = *(s32 *) (r0 + 0x34);
    r0    = *(u8 **) (r0 + 0x30);
    r3[0] = (s32) r0;
    r3[1] = r1;
    r3[2] = r2;
}
