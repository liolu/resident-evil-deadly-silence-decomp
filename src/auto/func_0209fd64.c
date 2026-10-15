/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200e5ec(M2C_UNK *, u16, u16);         /* extern */
M2C_UNK func_020fdd50(void *, M2C_UNK *, void *);   /* extern */
M2C_UNK func_02116dac(M2C_UNK, s32);                /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e68(s32);                             /* extern */
M2C_UNK func_0211809c(s32, M2C_UNK);                /* extern */
extern M2C_UNK data_027e0100;

void func_0209fd64(void *arg0, void *arg1, void *arg2) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    func_0200e5ec(&data_027e0100, (u16) (M2C_FIELD(arg2, s16 *, 2) * 0x10), (u16) (M2C_FIELD(arg2, s16 *, 4) * 0x10));
    func_020fdd50(arg1, &data_027e0100, arg1);
    temp_r0 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_r0 > 0) {
        func_02116dac(0x3F000000, func_02117e68(temp_r0 << 0xC));
    } else {
        func_0211809c(func_02117e68(temp_r0 << 0xC), 0x3F000000);
    }
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0) + func_02117dac());
    temp_r0_2                 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r0_2 > 0) {
        func_02116dac(0x3F000000, func_02117e68(temp_r0_2 << 0xC));
    } else {
        func_0211809c(func_02117e68(temp_r0_2 << 0xC), 0x3F000000);
    }
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) + func_02117dac());
    temp_r0_3                 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_r0_3 > 0) {
        func_02116dac(0x3F000000, func_02117e68(temp_r0_3 << 0xC));
    } else {
        func_0211809c(func_02117e68(temp_r0_3 << 0xC), 0x3F000000);
    }
    M2C_FIELD(arg1, s32 *, 8) = (s32) (M2C_FIELD(arg1, s32 *, 8) + func_02117dac());
}
