/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02013e28(M2C_UNK);

void func_02013ec8(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x19) = 1;
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s8 *, 0x17) = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0xA) = 0x7FFF;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    func_02013e28(arg0);
}
