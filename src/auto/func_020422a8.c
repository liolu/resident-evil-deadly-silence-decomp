/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_020422a8(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0x93)  = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    M2C_FIELD(arg0, s16 *, 0xA6) = 0x96;
    func_020559cc(arg0, 6);
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 3;
    func_020559cc(arg0, 6);
}
