/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_0211035c(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02110474(M2C_UNK *, s32, s32);         /* extern */
extern M2C_UNK data_02152588;
extern M2C_UNK data_021525f0;

void func_020e4a28(s32 a0, ...) {
    func_0211035c(&data_021525f0, 0, 0x80);
    func_02110474(&data_021525f0, a0, ((s32) &a0 & ~3) + 4);
    if (M2C_FIELD(&data_02152588, M2C_UNK(**)(s32, M2C_UNK *), 0) == NULL) {
        return;
    }
    M2C_FIELD(&data_02152588, M2C_UNK(**)(s32, M2C_UNK *), 0)(M2C_FIELD(&data_02152588, s32 *, 4), &data_021525f0);
}
