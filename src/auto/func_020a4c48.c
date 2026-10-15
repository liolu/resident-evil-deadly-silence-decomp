/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_020039b8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02003b00(M2C_UNK);                     /* extern */
M2C_UNK func_02005fcc(M2C_UNK *);                   /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_0200f7f0(M2C_UNK);                     /* extern */
M2C_UNK func_02013638(M2C_UNK, M2C_UNK, s32);       /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020a4610();                            /* extern */
M2C_UNK func_020b842c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_020c46e8(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_021007e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_0212140c;
extern M2C_UNK data_02121460;
extern M2C_UNK data_021214c4;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK func_020a42ec;
extern M2C_UNK func_020a49a8;

void func_020a4c48(void) {
    *(u16 *) 0x04000304 &= ~0x8000;
    func_020ff204(1, 0, 0);
    func_0200f7f0(4);
    func_0200f768(0x12);
    func_021007e8(0x04000050, 4, 8, 0x16, 0xA);
    func_020039b8(1, 0x10);
    func_020c3c0c(&data_0213b8ac, &func_020a42ec, 0, 0x2830);
    func_020038b8(&data_021214c4);
    func_02005fcc(&data_0212140c);
    func_020a4610();
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4) =
        (s32) * ((M2C_UNK *) ((s8 *) &data_02121460 + (M2C_FIELD(&data_0213ad48, u8 *, 3) * 4)));
    func_02013638(0, 0, M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4));
    func_020b842c(4, 2);
    func_020c4798(1);
    func_0206fcf8(0, 2, 0, 0x100);
    func_02003b00(2);
    func_020c46e8(&func_020a49a8, 0);
}
