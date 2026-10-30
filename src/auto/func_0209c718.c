/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_0209c6c0(M2C_UNK);                          /* extern */
M2C_UNK func_020b8324(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213d1a0;

void func_0209c718(void) {
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r4;
    u8 var_r0;

    temp_r4 = M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59);
    if ((M2C_FIELD(&data_0213d1a0, u16 *, 0x18) & (1 << temp_r4)) || (temp_r4 == 4)) {
        if (M2C_FIELD(&data_0213ad3c, u16 *, 6) & 4) {
            temp_r0 = func_0209c6c0(-1);
            if (temp_r0 != -1U) {
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = temp_r0;
            }
        } else if (M2C_FIELD(&data_0213ad3c, u16 *, 6) & 8) {
            temp_r0_2 = func_0209c6c0(1);
            if (temp_r0_2 != -1U) {
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = temp_r0_2;
            } else {
                M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = 4U;
            }
        }
    } else {
        var_r0 = func_0209c6c0(-1);
        if (var_r0 == -1U) {
            var_r0 = func_0209c6c0(1);
        }
        if (var_r0 != -1U) {
            M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = var_r0;
        } else {
            M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59) = 4U;
        }
    }
    if (temp_r4 != M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F59)) {
        func_020b8324(0x5D);
    }
}
