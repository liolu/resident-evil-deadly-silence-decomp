/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_02158820;
extern s32 data_027e0248;

s32 func_02102914(u32 arg0) {
    s32 i;
    s32 *p;
    u32 x;

    x = arg0;
    p = &data_027e0248;
    i = 0;
loop:
    if (x & 1) {
        if ((i >= 8) && (i <= 0xB)) {
            return *(s32 *) ((u8 *) &data_02158820 + (i - 8) * 0xC);
        }
        if ((i >= 3) && (i <= 6)) {
            return *(s32 *) ((u8 *) &data_02158820 + (i + 1) * 0xC);
        }
        return *p;
    }
    i += 1;
    x = x >> 1;
    p += 1;
    if (i >= 0x16) {
        return 0;
    }
    goto loop;
}
