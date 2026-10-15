/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02118728(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021374cc;

void func_02085c54(s32 arg0) {
    u32 temp_r1;

    temp_r1 = (func_02118728(arg0 + 9, 0xA) * 0xA) + M2C_FIELD(&data_021374cc, u32 *, 0x1C);
    if (temp_r1 > 0x98967FU) {
        M2C_FIELD(&data_021374cc, u32 *, 0x1C) = 0x98967FU;
        return;
    }
    M2C_FIELD(&data_021374cc, u32 *, 0x1C) = temp_r1;
}
