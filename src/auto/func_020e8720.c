/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK (*data_02153df8)(s32, M2C_UNK, M2C_UNK);
extern s32 data_02153dfc;

void func_020e8720(M2C_UNK arg0, M2C_UNK arg1) {
    if (data_02153df8 == NULL) {
        return;
    }
    data_02153df8(data_02153dfc, arg1, arg0);
}
