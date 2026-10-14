/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02004aec(void);

extern M2C_UNK data_02136ea8;

s32 func_02004b58(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_02136ea8, s32 *, 0) = arg0;
    M2C_FIELD(&data_02136ea8, s32 *, 4) = (s32) ((M2C_FIELD(&data_02136ea8, s32 *, 4) & 0xFF000000) | (((M2C_FIELD(arg0, s32 *, 0xC) * arg1) + M2C_FIELD(arg0, s32 *, 0)) & ~0xFF000000));
    M2C_FIELD(&data_02136ea8, s8 *, 7) = 0;
    return func_02004aec();
}
