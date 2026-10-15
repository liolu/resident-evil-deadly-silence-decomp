/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020f4414();                    /* extern */

void func_020f43ac(s32 *arg0, M2C_UNK arg1) {
    if ((func_020f4414(((s8 *) arg0 + 8)) == 0) && (func_020f4414(((s8 *) arg0 + 0x10), arg1) == 0) &&
        (func_020f4414(((s8 *) arg0 + 0x18), arg1) == 0)) {
        return;
    }
    *arg0 |= 0x10;
}
