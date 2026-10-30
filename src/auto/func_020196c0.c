/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0201893c(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_020189a4(M2C_UNK, void *);             /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02143cc0;

s32 func_020196c0(void *arg0) {
    s32 var_r0;
    u8 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s8 *, 0xA2) = 0;
        M2C_FIELD(arg0, s8 *, 0xA3) = 0;
        M2C_FIELD(arg0, s8 *, 0xA1) = 0xF;
        func_0205597c(0xC);
        if (M2C_FIELD(arg0, u8 *, 0x18E) == 0) {
            func_020189a4(9, arg0);
            M2C_FIELD(arg0, u8 *, 0x18E) = 0x96U;
        }
    }
    var_r0 = func_0201893c(arg0, 0, 0x400);
    if (var_r0 != 0) {
        M2C_FIELD(arg0, s8 *, 0x90)   = 1;
        M2C_FIELD(arg0, s8 *, 0x91)   = 0;
        M2C_FIELD(arg0, s8 *, 0x92)   = 1;
        M2C_FIELD(arg0, u8 *, 0x93)   = 0U;
        M2C_FIELD(arg0, s16 *, 0x176) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
        M2C_FIELD(arg0, s16 *, 0x178) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
        M2C_FIELD(arg0, s8 *, 0x96)   = 0;
        var_r0                        = M2C_FIELD(arg0, u8 *, 0xC0) & 8;
        if (var_r0 == 0) {
            temp_r1 = M2C_FIELD(arg0, u8 *, 0xA);
            var_r0  = temp_r1 & 0x20;
            if (var_r0 == 0) {
                var_r0 = temp_r1 & 0xF;
                if (var_r0 == 3) {
                    var_r0                     = 2;
                    M2C_FIELD(arg0, u8 *, 0xA) = 2U;
                }
            }
        }
    }
    return var_r0;
}
