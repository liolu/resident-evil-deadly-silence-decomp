/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02003ba0();                            /* extern */
s8 func_02005f54(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_0200f7f0(M2C_UNK);                     /* extern */
M2C_UNK func_0201367c();                            /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02085acc(s32);                         /* extern */
M2C_UNK func_02085adc(s32, M2C_UNK);                /* extern */
M2C_UNK func_0208e710(M2C_UNK);                     /* extern */
M2C_UNK func_0208ec54();                            /* extern */
M2C_UNK func_020b842c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c3c0c(void *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK data_0211ffa8;
extern void *data_02137894;
extern void *data_02137898;
extern M2C_UNK func_0208d8d4;
extern M2C_UNK func_0208efe0;

void func_0208f684(void) {
    s32 temp_r4;

    func_020c3c0c(data_02137894, 0, 0, 0x81C);
    temp_r4 = M2C_FIELD(data_02137894, s32 *, 0x30);
    *(u16 *)0x04000304 &= ~0x8000;
    func_0200f7f0(8);
    func_020ff204(1, 0, 0);
    func_0200f768(0xC);
    func_0208e710(1);
    func_020038b8(&data_0211ffa8);
    M2C_FIELD(data_02137894, s8 *, 0x14) = func_02005f54(0, 0x19, 0x48, 0);
    func_02085adc(temp_r4, 0);
    func_02085acc(temp_r4);
    func_02003ba0();
    func_0208ec54();
    func_0201367c();
    func_020b842c(4, 2);
    func_020b842c(6, 0xBF);
    M2C_FIELD(data_02137894, M2C_UNK **, 0x28) = &func_0208efe0;
    M2C_FIELD(data_02137894, s8 *, 8) = 0;
    M2C_FIELD(data_02137894, s8 *, 9) = 0;
    M2C_FIELD(data_02137894, s8 *, 0) = 0;
    M2C_FIELD(data_02137894, s8 *, 3) = 0;
    M2C_FIELD(data_02137894, u8 *, 4) = (u8) (M2C_FIELD(data_02137894, u8 *, 4) + 1);
    M2C_FIELD(data_02137894, s8 *, 5) = 0;
    M2C_FIELD(data_02137894, s8 *, 6) = 0;
    M2C_FIELD(data_02137894, s16 *, 0xA) = 0xA;
    M2C_FIELD(data_02137898, M2C_UNK **, 0x24) = &func_0208d8d4;
    M2C_FIELD(data_02137898, s8 *, 4) = 0;
    M2C_FIELD(data_02137898, s32 *, 0x28) = 0;
    func_0206fcf8(4, 2, 0, 0x80);
}
