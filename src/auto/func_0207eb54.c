/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02082e2c(M2C_UNK);

void func_0207eb54(s32 arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x93) = 0x18;
    func_02082e2c(arg0);
    if (((u32) (M2C_FIELD(arg0, u8 *, 7) << 0x1D) >> 0x1F) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1C8) = 2;
    } else {
        M2C_FIELD(arg0, s32 *, 0x1C8) = 1;
    }
    M2C_FIELD(arg0, s32 *, 0x1CC) = 1;
}
