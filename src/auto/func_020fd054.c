/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fd020(M2C_UNK);
void func_021067e4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02106d0c(void);
void func_02106ddc(M2C_UNK);
void func_02106e6c(M2C_UNK);
void func_0210ac28(M2C_UNK);
void func_0210ac40(M2C_UNK);

void func_020fd054(s32 arg0) {
    s32 temp_r5;

    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F) != 0) {
        func_021067e4(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
        func_0210ac40(arg0 + 8);
        func_0210ac28(arg0 + 0x14);
        M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~2);
        temp_r5                      = func_02106d0c();
        func_02106e6c(1);
        func_02106ddc(temp_r5);
    }
    func_020fd020(arg0);
}
