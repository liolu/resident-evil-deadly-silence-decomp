/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_01ffd504(M2C_UNK);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);

void func_0204225c(s32 arg0) {
    func_02075738(0, 0x400);
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0x17) {
        M2C_FIELD(arg0, s8 *, 0x90) = 1;
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
        M2C_FIELD(arg0, u8 *, 0xA2) = 0U;
    }
    func_01ffd504(0);
}
