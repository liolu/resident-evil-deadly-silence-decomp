/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02031214();                            /* extern */
M2C_UNK func_020558c0(s32, M2C_UNK);                /* extern */
M2C_UNK func_02091624(s32, s32, s32);               /* extern */
extern M2C_UNK data_0213af30;
extern s32 data_027e000c;
extern M2C_UNK func_02031514;

void func_020333dc(void) {
    M2C_FIELD(&data_0213af30, M2C_UNK **, 0x1C) = &func_02031514;
    func_020558c0(data_027e000c, 0xC);
    func_02091624(data_027e000c + 0x54, 0x400CCCCD, 0x3FCCCCCD);
    func_02031214();
}
