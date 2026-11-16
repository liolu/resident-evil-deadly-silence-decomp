/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02147cc0[];
extern u8 data_0214838c[];

u32 func_02074cf4(s32 arg0) {
    u8 *p;
    u32 end;

    p   = data_0214838c;
    end = *(u32 *) (data_02147cc0 + 0x84C);
    while ((u32) p <= end) {
        if (p[0] == 4) {
            if (((u8 *) *(u32 *) (p + 8))[0x14] == arg0) {
                return (u32) p;
            }
        }
        p += 12;
    }
    return 0;
}
