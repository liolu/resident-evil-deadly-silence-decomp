/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0214838c[];
extern u8 *data_027e000c;
extern u8 data_02147cc0[];
s32 func_01ffaa3c(s32, s32);

void func_0203113c(void) {
    u8 *r4;
    u8 b1;

    r4 = data_0214838c;
    while ((u32) r4 <= *(u32 *) (data_02147cc0 + 0x84C)) {
        if (r4[0] == 0x11) {
            b1 = r4[1];
            if ((((s32) b1 >> 7) ^ 1) != 0 && (b1 & 0x40)) {
                if (func_01ffaa3c((s32) (data_027e000c + 0x30), *(s32 *) (r4 + 8)) != 0) {
                    *(s32 *) (data_027e000c + 0x30) = *(s16 *) (data_027e000c + 0x3C);
                    return;
                }
            }
        }
        r4 += 0xC;
    }
}
