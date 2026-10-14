/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0201df30(M2C_UNK, M2C_UNK);
M2C_UNK func_0201eb38(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02143cc0;

s32 func_0201e904(s32 arg0, s32 arg1) {
    return func_0201eb38(arg0, (s32) (s16) (func_0201df30(M2C_FIELD(&data_02143cc0, s32 *, 0xF74), M2C_FIELD(&data_02143cc0, s32 *, 0xF7C)) - M2C_FIELD(arg0, s16 *, 0x44)), arg1);
}
