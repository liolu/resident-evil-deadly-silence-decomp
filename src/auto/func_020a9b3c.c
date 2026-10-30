/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020a9d18();                                /* extern */
s32 func_020a9d58(s32);                             /* extern */
M2C_UNK func_020ac2a4(M2C_UNK);                     /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213be00;

s32 func_020a9b3c(void *arg0) {
    s32 temp_r0;
    s32 var_r0_2;
    s8 var_r0;
    u8 temp_r0_2;

    temp_r0 = M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x200;
    if (temp_r0 != 0) {
        if (func_020a9d58(temp_r0) != 0) {
            M2C_FIELD(arg0, s8 *, 0x92) = 0x14;
            if (M2C_FIELD(arg0, u8 *, 0xA) == 6) {
                var_r0 = 3;
            } else {
                var_r0 = 0;
            }
            M2C_FIELD(arg0, s8 *, 0x93) = var_r0;
            return 1;
        }
        if (M2C_FIELD(&data_0213ad98, u16 *, 0x22) & 0x200) {
            if ((func_020b39e4(&data_0213be00, 0x7A) != 0) && (M2C_FIELD(arg0, u8 *, 0xA) == 5)) {
                var_r0_2 = 1;
            } else {
                var_r0_2 = 0;
            }
            if (var_r0_2 == 0) {
                func_020ac2a4(0);
            }
            if (func_020a9d18() != 0) {
                temp_r0_2 = M2C_FIELD(arg0, u8 *, 0xA);
                if ((temp_r0_2 != 6) && (temp_r0_2 != 0xA)) {
                    M2C_FIELD(arg0, s8 *, 0x92) = 0x18;
                    M2C_FIELD(arg0, s8 *, 0x93) = 0;
                    return 1;
                }
            }
            goto block_17;
        }
        goto block_17;
    }
block_17:
    return 0;
}
