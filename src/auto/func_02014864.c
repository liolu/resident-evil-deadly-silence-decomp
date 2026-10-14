/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020901fc(M2C_UNK, M2C_UNK);
void func_02090234(M2C_UNK, M2C_UNK);
M2C_UNK func_0209052c(M2C_UNK, M2C_UNK);

void func_02014864(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0x17) = (u8) func_0209052c(1, 0x20);
    func_02090234((s32) M2C_FIELD(arg0, u8 *, 0x17), 2);
    func_020901fc((s32) M2C_FIELD(arg0, u8 *, 0x17), 1);
    M2C_FIELD(arg0, s8 *, 0x16) = 0;
    M2C_FIELD(arg0, s16 *, 0x32) = 0;
    M2C_FIELD(arg0, u8 *, 0x19) = (u8) (M2C_FIELD(arg0, u8 *, 0x19) + 1);
}
