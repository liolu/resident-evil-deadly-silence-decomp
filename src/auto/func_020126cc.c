/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
s32 func_0211851c(s16, M2C_UNK);                    /* extern */
extern M2C_UNK data_0211bc32;
extern void *data_0213ad2c;

void func_020126cc(void *arg0, void *arg1) {
    s16 temp_r0;

    if ((u32) M2C_FIELD(arg1, u8 *, 0xE4) < 0x78U) {
        M2C_FIELD(arg1, s32 *, 0)    = (s32) (M2C_FIELD(arg1, s32 *, 0) + func_0211851c(M2C_FIELD(arg1, s16 *, 0x12), 0x64));
        M2C_FIELD(arg1, s16 *, 0x14) = (s16) (M2C_FIELD(arg1, s16 *, 0x14) - 2);
        if ((s32) M2C_FIELD(arg1, s16 *, 0x14) < -0x10) {
            temp_r0 = M2C_FIELD(arg1, s16 *, 0x16);
            if (temp_r0 == 0) {
                M2C_FIELD(arg1, s16 *, 0x14) = 0x10;
            } else {
                M2C_FIELD(arg1, s16 *, 0x16) = (s16) (temp_r0 - 1);
            }
        } else {
            M2C_FIELD(arg1, s16 *, 0x16) = 0xA;
            M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + func_0211851c(M2C_FIELD(arg1, s16 *, 0x14), 0xC));
        }
    }
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0) {
        M2C_FIELD(arg0, s8 *, 4) = 2;
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc32 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
}
