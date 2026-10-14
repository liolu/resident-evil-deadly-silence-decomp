/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02105c14(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_021060b8(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02136b8c;

void func_0210205c(s32 arg0, s32 arg1, s32 arg2) {
    if ((data_02136b8c != -1) && ((u32) arg2 > 0x30U)) {
        func_02105c14(data_02136b8c, arg0, arg1 + 0x07000000, arg2);
        return;
    }
    func_021060b8(arg0, arg1 + 0x07000000, arg2);
}
