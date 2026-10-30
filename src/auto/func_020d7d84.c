/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02141cc0;

s32 func_020d7d84(void) {
    if (M2C_FIELD(&data_02141cc0, s32 *, 0x40) != 2) {
        return 0;
    }
    func_020d880c(3);
    return 1;
}
