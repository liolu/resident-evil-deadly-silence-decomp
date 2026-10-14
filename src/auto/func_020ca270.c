/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8();                   /* extern */
M2C_UNK func_02003a0c();                     /* extern */
M2C_UNK func_02003b00();                     /* extern */
M2C_UNK func_02005fcc();                   /* extern */
M2C_UNK func_0200f768();                     /* extern */
M2C_UNK func_0200f9b8(); /* extern */
M2C_UNK func_0200fa10();            /* extern */
M2C_UNK func_0200fa84();            /* extern */
M2C_UNK func_02013638(); /* extern */
M2C_UNK func_0206fcf8(); /* extern */
M2C_UNK func_020c01c0();                            /* extern */
M2C_UNK func_020c01dc(); /* extern */
M2C_UNK func_020c36b8();            /* extern */
M2C_UNK func_020c3bd0();          /* extern */
M2C_UNK func_020c4798();                     /* extern */
M2C_UNK func_020ff204();   /* extern */
M2C_UNK func_021007e8(); /* extern */
extern M2C_UNK data_02125b68;
extern M2C_UNK data_02125b74;
extern M2C_UNK data_02125bf0;
extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_027e01ac;
extern M2C_UNK func_020c9d44;

void func_020ca270(void) {
    func_020ff204(1, 0, 0);
    func_0200f768(2);
    func_02003a0c(2);
    func_020038b8(&data_02125bf0);
    func_02005fcc(&data_02125b68);
    func_02003a0c(1);
    func_02003b00(2);
    M2C_FIELD(&data_0213b890, M2C_UNK **, 0x44) = &func_020c9d44;
    func_020c3bd0(&data_0213b8ac, 0x34);
    func_020c01dc(M2C_FIELD(&data_0213b890, void **, 0x4C) + 4, 0, 0xC, 0xB, 0);
    func_020c01dc(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x1C, 2, 0, 0, 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0) = -1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 1) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 2) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 3) = -1;
    func_02013638(0, 0, &data_02125b74);
    func_020c01c0();
    M2C_FIELD(&data_027e01ac, s16 *, 0x20) = 0xBA;
    func_021007e8(0x04000050, 4, 8, 8, 0xE);
    func_0200f9b8(0x20, 0xB, 0xE0, 0x8E);
    func_0200fa84(0xC, 0);
    func_0200fa10(0x1A, 0);
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & ~0xE000) | 0x2000;
    M2C_FIELD(&data_0213af7c, s8 *, 0x20) = 1;
    M2C_FIELD(&data_0213af7c, s16 *, 0x28) = 0x28;
    func_020c36b8(0x97, 0);
    func_020c4798(1);
    func_0206fcf8(0, 1, 0, 0x80);
}
