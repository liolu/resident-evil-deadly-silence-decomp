/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern s32 data_021528b0;
extern M2C_UNK (*data_021528b8)(s32, M2C_UNK, M2C_UNK);

void func_020e543c(M2C_UNK arg0, M2C_UNK arg1) {
    if (data_021528b8 == NULL) {
        return;
    }
    data_021528b8(data_021528b0, arg1, arg0);
}
