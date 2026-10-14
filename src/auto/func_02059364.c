/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056ea0(void *, M2C_UNK);             /* extern */

s32 func_02059364(void *arg0) {
    func_02056ea0(arg0, 3);
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 1) == 0x10) {
        return 2;
    }
    return 0xA;
}
