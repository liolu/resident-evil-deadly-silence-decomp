/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_021094e8(void *, M2C_UNK);                 /* extern */
M2C_UNK func_02109838();                            /* extern */

s32 func_02070324(void *arg0, M2C_UNK arg1) {
    func_02109838();
    if (func_021094e8(arg0, arg1) != 0) {
        return M2C_FIELD(arg0, s32 *, 0x24) - M2C_FIELD(arg0, s32 *, 0x20);
    }
    return -1;
}
