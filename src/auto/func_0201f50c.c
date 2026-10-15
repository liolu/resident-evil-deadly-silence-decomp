/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_01ffd504(M2C_UNK);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);
void func_020b8110(M2C_UNK, M2C_UNK);

void func_0201f50c(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0xA) = 4;
    if (func_02075738(0, 0x400) != 0) {
        M2C_FIELD(arg0, s8 *, 0x90)  = 1;
        M2C_FIELD(arg0, s8 *, 0x91)  = 0;
        M2C_FIELD(arg0, s8 *, 0x96)  = 0;
        M2C_FIELD(arg0, s8 *, 0x194) = (s8) (M2C_FIELD(arg0, s8 *, 0x194) & ~0x80);
        func_020b8110(0x4A, 0);
    }
    func_01ffd504(0);
}
