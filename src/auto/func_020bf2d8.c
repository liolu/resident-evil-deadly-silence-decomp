/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020bf2d8(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == arg0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x17) = -1;
        return;
    }
    if (arg2 != arg0) {
        return;
    }
    if (M2C_FIELD(&data_0213b890, u8 *, 0x20) != 2) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x18) = -1;
    }
}
