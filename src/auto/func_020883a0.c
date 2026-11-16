/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_021375ac[];

s32 func_020883a0(void) {
    u8 *p = *(u8 **) (data_021375ac + 0x64);

    if (p[0x17B] != 1) {
        return 0;
    }
    if (p[0x92] == 9) {
        if (p[0x286] == 4) {
            return 1;
        }
    } else {
        if (p[0x286] == 2) {
            return 2;
        }
    }
    return 0;
}
