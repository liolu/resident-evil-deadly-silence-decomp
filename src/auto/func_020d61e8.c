/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_020133a8(M2C_UNK);                          /* extern */
s32 func_020b8324(M2C_UNK);                         /* extern */
s32 func_020c4778(M2C_UNK);                         /* extern */
s32 func_020d6060(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213b890;

s32 func_020d61e8(void) {
    s32 var_r0;
    u8 temp_r0;

    M2C_FIELD(&data_0213b890, s8 *, 0x51) = 2;
    if (M2C_FIELD(&data_0213b890, u8 *, 0x55) == 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x55) = 1U;
        M2C_FIELD(&data_0213b890, u8 *, 0x59) = 0U;
        M2C_FIELD(&data_0213b890, u8 *, 0x57) = 0U;
        M2C_FIELD(&data_0213b890, u8 *, 0x52) = 0U;
        return 0;
    }
    if (M2C_FIELD(&data_0213b890, u8 *, 0x59) == 0) {
        if (M2C_FIELD(&data_0213ad3c, u16 *, 0) & 1) {
            M2C_FIELD(&data_0213b890, u8 *, 0x57) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x57) + 1);
            if ((u32) M2C_FIELD(&data_0213b890, u8 *, 0x57) > 0xB4U) {
                M2C_FIELD(&data_0213b890, u8 *, 0x59) = 1U;
            }
        } else {
            M2C_FIELD(&data_0213b890, u8 *, 0x57) = 0U;
        }
    }
    temp_r0 = func_020133a8(1);
    if (temp_r0 == -1U) {
        if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x20) {
            func_020c4778(2);
            return func_020b8324(0xE);
        }
        if (func_020d6060(0) != 0) {
            func_020c4778(4);
        }
        var_r0 = M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0xC;
        if (var_r0 != 0) {
            M2C_FIELD(&data_0213b890, u8 *, 0x52) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x52) ^ 1);
            return func_020b8324(0xC);
        }
        /* Duplicate return node #18. Try simplifying control flow for better match */
        return var_r0;
    }
    if (temp_r0 == M2C_FIELD(&data_0213b890, u8 *, 0x52)) {
        return func_020c4778(4);
    }
    M2C_FIELD(&data_0213b890, u8 *, 0x52) = temp_r0;
    var_r0                                = func_020b8324(0xC);
    return var_r0;
}
