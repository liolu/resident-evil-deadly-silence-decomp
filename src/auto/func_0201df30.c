/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_01ff9fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

s32 func_0201df30(s32 arg0, s32 arg1) {
    return (s32) (s16) func_01ff9fd8(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38), arg0, arg1);
}
