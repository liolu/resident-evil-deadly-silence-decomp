/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02005fcc(M2C_UNK *);                   /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_02013638(M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b7270();                            /* extern */
M2C_UNK func_020bd478(s32, M2C_UNK);                /* extern */
M2C_UNK func_020c3708(u8, M2C_UNK);                 /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020f4c1c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
extern M2C_UNK data_02124a08;
extern M2C_UNK data_02124a1c;
extern M2C_UNK data_02124a48;
extern M2C_UNK data_02124a88;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_0213ba90;
extern M2C_UNK func_020bd560;
extern M2C_UNK func_020bd57c;

void func_020bdf34(void) {
    func_0200f768(9);
    func_020038b8(&data_02124a48);
    func_02005fcc(&data_02124a08);
    func_020c3c0c(&data_0213b8ac, &func_020bd57c, &func_020bd560, 0x60);
    func_020b7270();
    func_02013638(0, 0, &data_02124a1c);
    func_02013638(1, 0, &data_02124a88);
    func_020c3708(M2C_FIELD(&data_0213b890, u8 *, 9), 1);
    M2C_FIELD(&data_0213b890, s32 *, 0x264) = -0x32;
    M2C_FIELD(&data_0213b890, s32 *, 0x274) = 0x14C;
    M2C_FIELD(&data_0213ba90, s16 *, 0x24)  = 0x7FFF;
    func_020f4c1c(1, 0, 2, 0, 0x1F, 0);
    func_020bd478(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x10, 0);
    *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & ~0x1F00) | 0x1D00;
    func_020c4798(1);
    func_0206fcf8(0, 2, 0, 0x100);
}
