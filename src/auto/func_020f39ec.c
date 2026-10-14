/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f356c(M2C_UNK *, M2C_UNK *, M2C_UNK, s32); /* extern */
s32 func_020f35e0(s32, u32);                        /* extern */
M2C_UNK func_020f3630(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02154390;
extern M2C_UNK data_02154394;

void func_020f39ec(void) {
    M2C_FIELD(&data_02154390, s32 *, 4) = func_020f35e0(M2C_FIELD(&data_02154390, s32 *, 0xC), (u32) M2C_FIELD(&data_02154390, u32 *, 0x10) >> 4);
    func_020f3630(&data_02154390);
    func_020f356c(&data_02154390, &data_02154394, 0, M2C_FIELD(&data_02154390, s32 *, 8));
}
