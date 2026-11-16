#include "m2c.h"

extern u8 data_0211afc0[];

void func_02003b24(s32 arg0) {
    s32 sel;
    u32 hi;
    u32 full;
    u32 inv;

    if (arg0 >= 4) {
        sel = 1;
    } else {
        sel = 0;
    }
    if (sel == 0) {
        hi                           = *(volatile u32 *) 0x04000000 & 0x1F00;
        full                         = *(volatile u32 *) 0x04000000;
        inv                          = ~data_0211afc0[arg0];
        *(volatile u32 *) 0x04000000 = (full & ~0x1F00) | ((inv & (hi >> 8)) << 8);
        return;
    }
    hi                           = *(volatile u32 *) 0x04001000 & 0x1F00;
    full                         = *(volatile u32 *) 0x04001000;
    inv                          = ~data_0211afc0[arg0];
    *(volatile u32 *) 0x04001000 = (full & ~0x1F00) | ((inv & (hi >> 8)) << 8);
}
