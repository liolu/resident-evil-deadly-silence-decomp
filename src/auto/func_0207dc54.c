/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02082df8(M2C_UNK);

void func_0207dc54(s32 arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x93)  = 0x14;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x34) = -0x2000;
    M2C_FIELD(arg0, s32 *, 0x1C8)                       = 0x80;
    M2C_FIELD(arg0, u8 *, 5)                            = (u8) (M2C_FIELD(arg0, u8 *, 5) | 8);
    func_02082df8(arg0);
}
