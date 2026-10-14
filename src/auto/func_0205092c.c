/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);
void func_020b8110(M2C_UNK, M2C_UNK);

void func_0205092c(s32 arg0) {
    s16 temp_r2;

    M2C_FIELD(arg0, s8 *, 0x91) = 3;
    temp_r2 = M2C_FIELD(arg0, s16 *, 0x44);
    if (((s32) temp_r2 > 0x7FF) && ((s32) temp_r2 < 0x1000)) {
        func_020559cc(arg0, 2);
    } else {
        func_020559cc(arg0, 9);
    }
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 7;
    M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 2);
    func_020b8110(0x77, 0);
}
