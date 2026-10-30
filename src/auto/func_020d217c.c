/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d2368();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020d217c(u32 arg0, u32 arg1) {
    if ((arg0 >= 0xF000U) && (arg1 < 0xF000U)) {
        M2C_FIELD(&data_0213b890, u8 *, 0x1D) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1D) - 1);
        func_020d2368();
    }
}
