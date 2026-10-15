/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ae60;

void func_02013638(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;

    temp_r4 = (arg0 * 0xC) + (s32) &data_0213ae60;
    func_021061d8(temp_r4, 0xFF, 0xC);
    M2C_FIELD(temp_r4, s8 *, 7)  = (s8) arg1;
    M2C_FIELD(temp_r4, s32 *, 8) = arg2;
    M2C_FIELD(temp_r4, s8 *, 5)  = 0;
    M2C_FIELD(temp_r4, s8 *, 6)  = 0;
}
