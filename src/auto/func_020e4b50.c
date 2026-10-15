/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern s32 data_02152580;
extern s32 data_02152584;
extern M2C_UNK data_021525a0;

void func_020e4b50(s32 arg0) {
    if (M2C_FIELD(&data_021525a0, M2C_UNK(**)(s32), 0) == NULL) {
        return;
    }
    M2C_FIELD(&data_021525a0, M2C_UNK(**)(s32), 0)(M2C_FIELD(&data_021525a0, s32 *, 4));
    if (data_02152580 == 0) {
        data_02152584 = arg0;
    }
    data_02152580 += 1;
}
