/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02118728(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021374cc;

void func_02085c9c(s32 arg0) {
    M2C_FIELD(&data_021374cc, s32 *, 0x2C) = (s32) (func_02118728(arg0 + 9, 0xA) * 0xA);
}
