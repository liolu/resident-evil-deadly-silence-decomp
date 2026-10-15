/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02005fcc(M2C_UNK *);                   /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_02013638(M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c01c0();                            /* extern */
M2C_UNK func_020c01dc(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020c36b8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK data_02125d24;
extern M2C_UNK data_02125d4c;
extern M2C_UNK data_02125d64;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK func_020cadbc;

void func_020cb450(void) {
    func_020ff204(1, 0, 0);
    func_0200f768(0x16);
    func_020038b8(&data_02125d64);
    func_02005fcc(&data_02125d24);
    func_020c3c0c(&data_0213b8ac, &func_020cadbc, 0, 0x38);
    func_020c01dc(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 8, 0, 8, 0xB, 0);
    func_020c01dc(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x20, 2, 9, 2, 1);
    *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & ~0x1F00) | 0x1800;
    func_02013638(0, 0, &data_02125d4c);
    func_020c01c0();
    M2C_FIELD(&data_0213b890, s8 *, 0x24) = 5;
    func_02092dd4(0xE, 0);
    func_020c36b8(0x97, 0xAD);
    func_020c4798(1);
    func_0206fcf8(0, 2, 0, 0x80);
}
