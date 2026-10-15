/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02005fcc(M2C_UNK *);                   /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_02013638(M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b842c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020bccd0();                            /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_021007e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_021249c0;
extern M2C_UNK data_021249cc;
extern M2C_UNK data_021249dc;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK func_020bcad0;

void func_020bd2dc(void) {
    func_020c3c0c(&data_0213b8ac, &func_020bcad0, 0, 0x48);
    M2C_FIELD(&data_0213b2b4, s8 *, 1) = 0;
    func_0200f768(4);
    func_020038b8(&data_021249dc);
    func_02005fcc(&data_021249c0);
    func_02013638(0, 0, &data_021249cc);
    func_020b842c(4, 2);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x40)  = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x24)  = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x28) = -0x8000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x2C) = -0x8000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xC)  = 0x8000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) = 0x8000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x25)  = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x41)  = 2;
    func_020bccd0();
    func_021007e8(0x04000050, 4, 0x18, 0x10, 8);
    *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & ~0x1F00) | 0x1E00;
    func_020c4798(1);
    func_0206fcf8(3, 2, 0, 0x80);
}
