/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020822dc(void *);                          /* extern */
u32 func_02082348(void *);                          /* extern */
M2C_UNK func_02082488(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02084b78(void *, M2C_UNK);             /* extern */
s32 func_0211851c(s32, s32);                        /* extern */

void func_02082bb8(void *arg0) {
    void *temp_r1;
    void *temp_r5;

    func_02084b78(arg0, 0x800);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1C8) < 0) {
        M2C_FIELD(arg0, u8 *, 5) = (u8) (M2C_FIELD(arg0, u8 *, 5) | 8);
        temp_r5                  = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r5, s32 *, 0x34) =
            (s32) (M2C_FIELD(temp_r5, s32 *, 0x34) -
                   (func_0211851c(M2C_FIELD(arg0, s32 *, 0x1C8), M2C_FIELD(arg0, s32 *, 0x1CC)) - 1));
        if ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x34) >= 0) {
            M2C_FIELD(arg0, s32 *, 0x1CC)                       = 0;
            M2C_FIELD(arg0, s32 *, 0x1C8)                       = (s32) M2C_FIELD(arg0, s32 *, 0x1CC);
            M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x34) = (s32) M2C_FIELD(arg0, s32 *, 0x1C8);
            M2C_FIELD(arg0, u8 *, 5)                            = (u8) (M2C_FIELD(arg0, u8 *, 5) & ~8);
        }
    }
    if ((((u32) (M2C_FIELD(arg0, u8 *, 7) << 0x18) >> 0x1F) != 0) && (func_02082348(arg0) <= 0xDU)) {
        func_02082488(arg0, 0x12, 0, 0);
    }
    if (func_020822dc(arg0) != 0) {
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
    }
}
