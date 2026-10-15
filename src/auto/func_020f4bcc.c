/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fe364(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021543a4;
extern M2C_UNK data_021543f0;
extern M2C_UNK data_021544a4;

s32 func_020f4bcc(void) {
    if (!(M2C_FIELD(&data_021543a4, s32 *, 0xFC) & 8)) {
        func_020fe364((s32) &data_021543f0, (s32) &data_021544a4);
        M2C_FIELD(&data_021543a4, s32 *, 0xFC) = (s32) (M2C_FIELD(&data_021543a4, s32 *, 0xFC) | 8);
    }
    return (s32) &data_021544a4;
}
