/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4798();                     /* extern */
extern M2C_UNK data_02126398;
extern M2C_UNK data_0213b890;

void func_020d09d4(void) {
    s32 var_r0;
    u16 temp_r2;
    u16 temp_r2_2;
    u8 temp_ip;
    u8 temp_ip_2;

    var_r0  = 0;
    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF0);
    if (temp_r2 != 0) {
        if (((u32) temp_r2 >= 0x3E8U) || ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xEE) >= 0x3E8U)) {
            if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF5) > 3U) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF5) = 3U;
            }
            temp_ip = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF5);
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF5) = (u8) (temp_ip + 1);
            temp_ip_2                                                       = ((s8 *) &data_02126398)[temp_ip];
            temp_r2_2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2);
            if ((s32) temp_ip_2 > (s32) temp_r2_2) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) = 0U;
                M2C_FIELD(&data_0213b890, s8 *, 0x24)                            = 2;
                func_020c4798();
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) = (u16) (temp_r2_2 - temp_ip_2);
            goto block_12;
        }
        if ((u32) temp_r2 >= 0x320U) {
            var_r0 = 0xE;
        } else if ((u32) temp_r2 >= 0x1F4U) {
            var_r0 = 8;
        }
    block_12:
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) =
            (u16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) + var_r0);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF0) = 0U;
        if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2) >= 0x46U) {
            M2C_FIELD(&data_0213b890, s8 *, 0x24) = 1;
            func_020c4798(2);
        }
    }
}
