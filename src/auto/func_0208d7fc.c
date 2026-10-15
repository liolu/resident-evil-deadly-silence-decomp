/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02003ba0();                            /* extern */
s8 func_02005f54(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0200f6e0(M2C_UNK);                     /* extern */
M2C_UNK func_02085acc(s32);                         /* extern */
M2C_UNK func_02085adc(s32, M2C_UNK);                /* extern */
M2C_UNK func_0208e710(M2C_UNK);                     /* extern */
M2C_UNK func_020c3c0c(void *, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0211fc1c;
extern void *data_02137898;
extern M2C_UNK func_0208d6d4;

void func_0208d7fc(void) {
    s32 temp_r4;

    func_020c3c0c(data_02137898, 0, 0, 0x814);
    temp_r4 = M2C_FIELD(data_02137898, s32 *, 0x30);
    func_0200f6e0(2);
    func_0208e710(0);
    func_020038b8(&data_0211fc1c);
    M2C_FIELD(data_02137898, s8 *, 0x14) = func_02005f54(0x81, 0x19, 0x48, 0);
    func_02085adc(temp_r4, 2);
    func_02085acc(temp_r4);
    func_02003ba0();
    M2C_FIELD(data_02137898, M2C_UNK **, 0x28) = &func_0208d6d4;
    M2C_FIELD(data_02137898, s8 *, 0)          = 0;
    M2C_FIELD(data_02137898, u8 *, 4)          = (u8) (M2C_FIELD(data_02137898, u8 *, 4) + 1);
    M2C_FIELD(data_02137898, s8 *, 5)          = 0;
    M2C_FIELD(data_02137898, s16 *, 0xA)       = 0xA;
    M2C_FIELD(data_02137898, s8 *, 9)          = 0;
}
