/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02088580();                              /* extern */

s32 func_0208495c(u32 arg0) {
    if (arg0 >= 0x10U) {
        return 0;
    }
    return M2C_FIELD(func_02088580(), s32 *, 0xDC) + (arg0 * 0x10);
}
