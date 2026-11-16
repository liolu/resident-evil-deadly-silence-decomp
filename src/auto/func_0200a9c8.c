/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void func_0200e174(s32 a, s32 b);
extern u8 *data_02137298;

void func_0200a9c8(s32 arg0) {
    u8 *e;

    e = data_02137298 + 0x1440 + (arg0 << 6);
    if (*(s32 *) (e + 0x38) & 4) {
        func_0200e174(arg0, 0);
        *(s32 *) (e + 0x3C) = 0;
        *(s32 *) (e + 0x38) = *(s32 *) (e + 0x38) & ~4;
        return;
    }
    func_0200e174(arg0, 1);
    *(s32 *) (e + 0x3C) = 1;
    *(s32 *) (e + 0x38) = *(s32 *) (e + 0x38) | 4;
}
