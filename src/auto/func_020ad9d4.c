/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a0518(s32, M2C_UNK, u8, M2C_UNK);   /* extern */
s32 func_020ada7c();                                /* extern */
extern M2C_UNK data_02121eb8;
extern s32 data_027e000c;

void func_020ad9d4(M2C_UNK arg0) {
    func_020a0518(data_027e000c, arg0, (u8) * ((u16 *) ((s8 *) &data_02121eb8 + (func_020ada7c() * 2))), 0);
}
