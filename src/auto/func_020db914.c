/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020db9d4(M2C_UNK);
void func_020dbb48(M2C_UNK);
void func_020e2f10(M2C_UNK);
void func_020e302c(M2C_UNK);
M2C_UNK func_020e30f4(M2C_UNK);

void func_020db914(s32 arg0) {
    s32 temp_r5;

    temp_r5 = arg0 + 0x48;
    if ((M2C_FIELD(arg0, s32 *, 4) == 1) && (func_020e30f4(M2C_FIELD(arg0, s32 *, 8)) == 0)) {
        M2C_FIELD(arg0, M2C_UNK(**)(s32, s32, s32, s32), 0x78)(M2C_FIELD(arg0, s32 *, 0x7C), temp_r5 + 0x20, temp_r5 + 0x24,
                                                               temp_r5 + 0x28);
        func_020dbb48(arg0);
        M2C_FIELD(arg0, s32 *, 4) = 2;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 2) {
        return;
    }
    func_020e2f10(M2C_FIELD(arg0, s32 *, 8));
    if (func_020e30f4(M2C_FIELD(arg0, s32 *, 8)) != 3) {
        return;
    }
    func_020db9d4(arg0);
    func_020e302c(M2C_FIELD(arg0, s32 *, 8));
    M2C_FIELD(arg0, M2C_UNK(**)(s32, s32, s32), 0x80)(M2C_FIELD(arg0, s32 *, 0x84), M2C_FIELD(arg0, s32 *, 0x94),
                                                      M2C_FIELD(arg0, s32 *, 0x90));
    M2C_FIELD(arg0, s32 *, 4) = 3;
}
