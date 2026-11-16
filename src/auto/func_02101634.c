/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02105a1c(s32, M2C_UNK, s32, s32, s32, s32); /* extern */
M2C_UNK func_021060b8(M2C_UNK, s32);                /* extern */
extern s32 data_02136b8c;

void func_02101634(M2C_UNK arg0, s32 arg1, s32 arg2) {
    if (data_02136b8c != -1) {
        func_02105a1c(data_02136b8c, arg0, arg1 + 0x06898000, arg2, 0, 0);
        return;
    }
    func_021060b8(arg0, arg1 + 0x06898000);
}
