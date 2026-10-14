/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020da2d4(M2C_UNK);
M2C_UNK func_020e0d64(M2C_UNK);
M2C_UNK func_020e0de8(M2C_UNK);

void func_020da00c(s32 arg0) {
    if (M2C_FIELD(arg0, s8 *, 1) == 2) {
        M2C_FIELD(arg0, s8 *, 1) = (s8) func_020e0de8(M2C_FIELD(arg0, s32 *, 4));
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) (func_020e0d64(M2C_FIELD(arg0, s32 *, 4)) - M2C_FIELD(arg0, s32 *, 0x14));
        if ((u32) (u8) (s8) (M2C_FIELD(arg0, s8 *, 1) - 3) <= 1U) {
            M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + M2C_FIELD(arg0, s32 *, 0x20));
            func_020da2d4(arg0);
        }
    }
    if (M2C_FIELD(arg0, s8 *, 3) != 1) {
        return;
    }
    if (func_020e0de8(M2C_FIELD(arg0, s32 *, 4)) != 1) {
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) (func_020e0d64(M2C_FIELD(arg0, s32 *, 4)) - M2C_FIELD(arg0, s32 *, 0x14));
    func_020da2d4(arg0);
    M2C_FIELD(arg0, s8 *, 1) = 1;
    M2C_FIELD(arg0, s8 *, 3) = 0;
}
