/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a0518(void *, M2C_UNK, u8, M2C_UNK); /* extern */
M2C_UNK func_020f8318(s32, M2C_UNK);                /* extern */
M2C_UNK func_020f8678(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0211d029;

void func_020558c0(void *arg0, M2C_UNK arg1) {
    func_020a0518(arg0, arg1, *((u8 *) ((s8 *) &data_0211d029 + (M2C_FIELD(arg0, u8 *, 9) * 8))), 0);
    func_020f8318(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xC), 9);
    func_020f8678(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xC), 1, 0x3F000000);
}
