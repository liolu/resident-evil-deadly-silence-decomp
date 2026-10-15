/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f28c8(M2C_UNK, M2C_UNK);
void func_020fce8c(M2C_UNK);
void func_020fcf04(M2C_UNK);

extern s32 data_02157c20;
extern M2C_UNK data_02157c24;

void func_020fd4dc(s32 arg0) {
    if (data_02157c20 == 0) {
        func_020f28c8((s32) &data_02157c24, 0);
        data_02157c20 = 1;
    }
    M2C_FIELD(arg0, void (**)(s32), 8)    = func_020fcf04;
    M2C_FIELD(arg0, s32 *, 0xC)           = arg0;
    M2C_FIELD(arg0, void (**)(s32), 0x14) = func_020fce8c;
    M2C_FIELD(arg0, s32 *, 0x18)          = arg0;
    M2C_FIELD(arg0, s32 *, 0x44)          = 0;
    M2C_FIELD(arg0, s32 *, 0x48)          = 0;
    M2C_FIELD(arg0, s32 *, 0x24)          = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~1);
    M2C_FIELD(arg0, s32 *, 0x24)          = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~2);
}
