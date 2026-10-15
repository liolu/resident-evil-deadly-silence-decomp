/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0209fd64(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020f7d84(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

void func_020a4fe0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0209fd64(arg0 + 0x30, arg1, arg0 + 0x42);
    M2C_FIELD(arg1, s32 *, 0) = func_0211851c(M2C_FIELD(arg1, s32 *, 0), 0x12);
    M2C_FIELD(arg1, s32 *, 4) = func_0211851c(0 - M2C_FIELD(arg1, s32 *, 4), 0x12);
    M2C_FIELD(arg1, s32 *, 8) = func_0211851c(0 - M2C_FIELD(arg1, s32 *, 8), 0x12);
    func_020f7d84(arg1, arg2, arg3);
}
