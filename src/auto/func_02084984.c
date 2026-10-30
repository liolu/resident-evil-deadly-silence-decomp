/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02088580();                              /* extern */

s32 func_02084984(u32 arg0) {
    if (arg0 >= 0x20U) {
        return 0;
    }
    return M2C_FIELD(func_02088580(), s32 *, 0xD8) + (arg0 * 0x10);
}
