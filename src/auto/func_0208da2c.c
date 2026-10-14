/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02003ba0();                            /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02085acc(s32);                         /* extern */
M2C_UNK func_02085adc(s32, M2C_UNK);                /* extern */
M2C_UNK func_0208db30();                            /* extern */
M2C_UNK func_0208e710(M2C_UNK);                     /* extern */
M2C_UNK func_020c3c0c(void *, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK data_0211fc00;
extern void *data_02137898;
extern void *data_0213789c;
extern M2C_UNK func_0208d908;

void func_0208da2c(void) {
    s32 temp_r4;

    func_020c3c0c(data_0213789c, &func_0208d908, 0, 0x814);
    temp_r4 = M2C_FIELD(data_0213789c, s32 *, 0x30);
    func_02085adc(temp_r4, 1);
    func_020ff204(1, 0, 0);
    func_0200f768(0xC);
    func_0208e710(1);
    func_020038b8(&data_0211fc00);
    func_02085acc(temp_r4);
    func_02003ba0();
    func_0208db30();
    M2C_FIELD(data_0213789c, u8 *, 4) = (u8) (M2C_FIELD(data_0213789c, u8 *, 4) + 1);
    M2C_FIELD(data_02137898, s8 *, 5) = 0;
    M2C_FIELD(data_0213789c, s8 *, 0) = 0;
    M2C_FIELD(data_0213789c, s16 *, 0xA) = 0xA;
    func_0206fcf8(3, 2, 0, 0x80);
}
