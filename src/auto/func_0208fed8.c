/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208fdbc();                            /* extern */
void *func_0208fe14();                              /* extern */
M2C_UNK func_02116dac(M2C_UNK, s32);                /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e68(s32);                             /* extern */
M2C_UNK func_0211809c(s32, M2C_UNK);                /* extern */
s32 func_0211851c(s32, M2C_UNK);                    /* extern */

void func_0208fed8(s32 arg0, void *arg1, void *arg2) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    s32 temp_r0_5;
    s32 temp_r0_6;
    s32 temp_r0_7;
    void *temp_r0;

    temp_r0 = func_0208fe14();
    if (temp_r0 != NULL) {
        func_0208fdbc();
        if (M2C_FIELD(temp_r0, u8 *, 0) == 1) {
            temp_r0_2 = M2C_FIELD(arg1, s32 *, 0);
            if (temp_r0_2 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_2 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_2 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 4) = func_0211851c(func_02117dac(), 0x12);
            temp_r0_3                    = M2C_FIELD(arg1, s32 *, 4);
            if (temp_r0_3 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_3 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_3 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 8) = (s32) (0 - func_0211851c(func_02117dac(), 0x12));
            temp_r0_4                    = M2C_FIELD(arg1, s32 *, 8);
            if (temp_r0_4 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_4 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_4 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 0xC) = (s32) (0 - func_0211851c(func_02117dac(), 0x12));
            temp_r0_5                      = M2C_FIELD(arg2, s32 *, 0);
            if (temp_r0_5 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_5 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_5 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 0x10) = func_0211851c(func_02117dac(), 0x12);
            temp_r0_6                       = M2C_FIELD(arg2, s32 *, 4);
            if (temp_r0_6 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_6 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_6 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 0x14) = (s32) (0 - func_0211851c(func_02117dac(), 0x12));
            temp_r0_7                       = M2C_FIELD(arg2, s32 *, 8);
            if (temp_r0_7 > 0) {
                func_02116dac(0x3F000000, func_02117e68(temp_r0_7 << 0xC));
            } else {
                func_0211809c(func_02117e68(temp_r0_7 << 0xC), 0x3F000000);
            }
            M2C_FIELD(temp_r0, s32 *, 0x18) = (s32) (0 - func_0211851c(func_02117dac(), 0x12));
            return;
        }
        M2C_FIELD(temp_r0, s32 *, 0xC)  = 0;
        M2C_FIELD(temp_r0, s32 *, 8)    = (s32) M2C_FIELD(temp_r0, s32 *, 0xC);
        M2C_FIELD(temp_r0, s32 *, 4)    = (s32) M2C_FIELD(temp_r0, s32 *, 8);
        M2C_FIELD(temp_r0, s32 *, 0x18) = 0;
        M2C_FIELD(temp_r0, s32 *, 0x14) = (s32) M2C_FIELD(temp_r0, s32 *, 0x18);
        M2C_FIELD(temp_r0, s32 *, 0x10) = (s32) M2C_FIELD(temp_r0, s32 *, 0x14);
    }
}
