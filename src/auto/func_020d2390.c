/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);
M2C_UNK func_020d2368();
u64 func_0211851c(u8, M2C_UNK);
extern M2C_UNK data_0213b890;

void func_020d2390(u32 arg0, u32 arg1) {
    if ((arg1 > 0xF000U) && (arg0 <= 0xF000U)) {
        M2C_FIELD(&data_0213b890, u8 *, 0x1D) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1D) + 1);
        if ((M2C_FIELD(&data_0213b890, u8 *, 0x1D) != 0) &&
            ((u32) (func_0211851c(M2C_FIELD(&data_0213b890, u8 *, 0x1D), 2) >> 32) == 0)) {
            func_020b82fc(0xD6);
        }
    }
    func_020d2368();
}
