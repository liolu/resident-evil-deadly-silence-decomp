#include "m2c.h"

s32 func_020f8a84(void *a0, s32 a1) {
    u16 idx = *(u16 *) ((u8 *) a0 + 0x12);
    u8 *p   = (u8 *) a0 + 0xc + idx;
    u16 v   = *(u16 *) p;
    return (s32) (p + 4) + v * a1;
}
