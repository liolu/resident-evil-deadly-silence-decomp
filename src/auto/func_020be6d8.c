/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_0200f7f0(M2C_UNK);                     /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02076444();                            /* extern */
M2C_UNK func_0207a294();                            /* extern */
M2C_UNK func_0209ff58();                            /* extern */
M2C_UNK func_020b842c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020bd478(s32, M2C_UNK);                /* extern */
s32 func_020be1c8();                                /* extern */
M2C_UNK func_020c3708(u8, M2C_UNK);                 /* extern */
M2C_UNK func_020c3b24();                            /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_020f4c1c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK data_02124ad4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_0213ba90;
extern M2C_UNK func_020be264;
extern M2C_UNK func_020be27c;

void func_020be6d8(void) {
    func_0200f7f0(6);
    func_0200f768(9);
    func_020c3c0c(&data_0213b8ac, &func_020be27c, &func_020be264, 0x50);
    M2C_FIELD(&data_0213b890, s8 *, 0x1E) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = 0;
    if (func_020be1c8() == 0) {
        func_0206fcf8(4, 1, 1, 0x100);
        M2C_FIELD(&data_0213b890, s8 *, 0x21) = 4;
        M2C_FIELD(&data_0213b890, s8 *, 0x22) = 0;
        M2C_FIELD(&data_0213b890, s8 *, 0x23) = 0;
        return;
    }
    func_0207a294();
    func_02076444();
    func_0209ff58();
    func_020b842c(5, 3);
    func_020038b8(&data_02124ad4);
    func_020c3b24();
    func_020c3708(M2C_FIELD(&data_0213b890, u8 *, 9), 1);
    M2C_FIELD(&data_0213b890, s32 *, 0x264) = -0x32;
    M2C_FIELD(&data_0213b890, s32 *, 0x274) = 0;
    M2C_FIELD(&data_0213ba90, s16 *, 0x24)  = 0x7FFF;
    func_020f4c1c(1, 0, 2, 0, 0x1F, 0);
    func_020bd478(M2C_FIELD(&data_0213b890, s32 *, 0x4C), 0);
    *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & ~0x1F00) | 0x1D00;
    func_0206fcf8(0, 1, 0, 0x100);
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
    M2C_FIELD(&data_0213b890, s8 *, 0x22) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x23) = 0;
}
