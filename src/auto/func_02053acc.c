/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s8 data_02143cc0[];

u32 func_02053acc(void) {
    u32 i;

    for (i = 0; i < 0x1E; i = (u8) (i + 1)) {
        if (data_02143cc0[i * 412 + 0x10EE] == 0) {
            return i;
        }
    }
    return 0xFF;
}
