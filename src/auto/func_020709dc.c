/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_0200e9d4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0211d8a0;
extern M2C_UNK data_02143cc0;

s32 func_020709dc(s32 arg0) {
    if (func_0200e9d4((s32) ((M2C_UNK *) ((s8 *) &data_0211d8a0 + (arg0 * 2))), (s32) M2C_FIELD(&data_02143cc0, u8 *, 0xF)) !=
        0) {
        return 1;
    }
    return 0;
}
