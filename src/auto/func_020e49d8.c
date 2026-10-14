/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_021126e0(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02152588;
extern M2C_UNK data_021525f0;

void func_020e49d8(s32 arg0) {
    func_021126e0((s32) &data_021525f0, arg0, 0x7F);
    if (M2C_FIELD(&data_02152588, M2C_UNK (**)(s32, M2C_UNK *), 0) == NULL) {
        return;
    }
    M2C_FIELD(&data_02152588, M2C_UNK (**)(s32, M2C_UNK *), 0)(M2C_FIELD(&data_02152588, s32 *, 4), &data_021525f0);
}
