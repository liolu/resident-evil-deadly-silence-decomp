/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020703b8(M2C_UNK);
void func_020761b8(M2C_UNK);
void func_020f3de4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020f4010(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_020f8758(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_02010e3c(s32 arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r5;

    temp_r0                              = func_020703b8(arg0);
    M2C_FIELD(arg1, s32 *, 0x7C)         = temp_r0;
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 1;
    func_020761b8(temp_r0);
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
    temp_r0_2                            = func_020f8758(temp_r0);
    M2C_FIELD(arg1, s32 *, 0x80)         = temp_r0_2;
    temp_r5                              = M2C_FIELD(arg1, s32 *, 0x24);
    func_020f4010(temp_r5, temp_r0_2, 0, 0);
    func_020f3de4(temp_r5, temp_r0_2, 0, 0);
}
