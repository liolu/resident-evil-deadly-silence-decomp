/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020035e4(M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_02005738();                            /* extern */
M2C_UNK func_0200582c(M2C_UNK);                     /* extern */
M2C_UNK func_020059f0(s32);                         /* extern */
s32 func_02005ad8();                                /* extern */
M2C_UNK func_0200f6e0(M2C_UNK);                     /* extern */
M2C_UNK func_0200f768(M2C_UNK);                     /* extern */
M2C_UNK func_0200f7f0(M2C_UNK);                     /* extern */
M2C_UNK func_0200f884();                            /* extern */
M2C_UNK func_0200fa98();                            /* extern */
M2C_UNK func_0200fae8();                            /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8c4c(s16, s16);                    /* extern */
M2C_UNK func_020c3bd0(M2C_UNK *, s32);              /* extern */
M2C_UNK func_020c3c0c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_021061d8(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_02123dfc;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_0213b8e0;

void func_020b8f5c(void) {
    func_020c3c0c(&data_0213b8ac, 0, 0, 0x28);
    func_020c3bd0(&data_0213b8e0, func_02005ad8());
    func_020059f0(M2C_FIELD(&data_0213b890, s32 *, 0x80));
    *(u16 *)0x04000304 |= 0x8000;
    func_020ff204(1, 0, 0);
    func_0200fae8();
    func_0200fa98();
    func_0200f884();
    func_0200f7f0(6);
    func_0200f768(0x14);
    func_0200f6e0(8);
    func_021061d8(M2C_FIELD(&data_0213b2b4, void **, 0xC8), 0, 0x8000);
    func_020035e4(1, M2C_FIELD(&data_0213b2b4, void **, 0xC8), 0, 0x8000);
    func_020035e4(5, M2C_FIELD(&data_0213b2b4, void **, 0xC8), 0, 0x8000);
    func_020038b8(&data_02123dfc);
    *(u16 *)0x0400000E = (*(u16 *)0x0400000E & 0x43) | 0x9E10;
    *(u16 *)0x0400100C = (*(u16 *)0x0400100C & 0x43) | 0x9C10;
    *(u16 *)0x0400100E = (*(u16 *)0x0400100E & 0x43) | 0x9E10;
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & ~0x1F00) | 0x200;
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~0x1F00) | 0x200;
    M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x150;
    func_021061d8(M2C_FIELD(&data_0213b890, void **, 0x4C), 0, 8);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 8) = 0xC000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x10) = -0x10000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x18) = -0x10000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20) = -0x10000;
    func_020b8c4c((s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0), (s16) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 8));
    func_0200582c(0x19);
    func_02005738();
    func_0206fcf8(4, 2, 0, 0x100);
    M2C_FIELD(&data_0213b890, s8 *, 0x20) = 1;
}
