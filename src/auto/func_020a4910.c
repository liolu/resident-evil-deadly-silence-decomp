/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020038b8(M2C_UNK *);                   /* extern */
M2C_UNK func_020039b8(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02003ad8(M2C_UNK);                     /* extern */
M2C_UNK func_02005fcc(s32);                         /* extern */
M2C_UNK func_0200f6e0(M2C_UNK);                     /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020a44d4();                            /* extern */
M2C_UNK func_020c4778(M2C_UNK);                     /* extern */
M2C_UNK func_021007e8(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02121490;
extern M2C_UNK data_021214a8;
extern M2C_UNK data_0213ad48;

void func_020a4910(void) {
    func_0200f6e0(9);
    func_021007e8(0x04001050, 4, 8, 0x16, 0xA);
    func_020039b8(5, 0x10);
    func_020038b8(&data_021214a8);
    func_02005fcc(*((M2C_UNK *)((s8 *)&data_02121490 + (M2C_FIELD(&data_0213ad48, u8 *, 3) * 4))));
    func_020a44d4();
    func_020c4778(1);
    func_02003ad8(2);
    func_0206fcf8(1, 2, 0, 0x100);
}
