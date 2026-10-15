/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020db88c(M2C_UNK);
M2C_UNK func_020dbde8(M2C_UNK);
void func_020df76c(M2C_UNK);
void func_020df7dc(M2C_UNK);
void func_020df9a4(M2C_UNK);

void func_020df6dc(s32 arg0) {
    s16 temp_r0;
    s32 temp_r4;

    temp_r4 = M2C_FIELD(arg0, s32 *, 4);
    if (func_020dbde8(temp_r4) == 0) {
        func_020df9a4(arg0);
    }
    func_020db88c(temp_r4);
    if (func_020dbde8(temp_r4) == 3) {
        func_020df7dc(arg0);
    }
    temp_r0 = M2C_FIELD(temp_r4, s16 *, 0x98);
    if ((temp_r0 != 0xA) && (temp_r0 != 0x14) && (temp_r0 != 0xB) && (temp_r0 != 0xC) && (temp_r0 != 0xF)) {
        return;
    }
    func_020df76c(arg0);
}
