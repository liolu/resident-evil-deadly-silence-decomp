/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02075f00(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_020f3d8c(s32);                         /* extern */
M2C_UNK func_020f3fa8(s32);                         /* extern */
M2C_UNK func_020f8678(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020f86e8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 data_021402e8;
extern M2C_UNK data_02143cc0;

void func_020add78(void *arg0, M2C_UNK arg1) {
    func_020f8678(M2C_FIELD(arg0, s32 *, 0xC), 0, 0xF);
    func_020f3fa8(M2C_FIELD(arg0, s32 *, 0xC));
    func_020f3d8c(M2C_FIELD(arg0, s32 *, 0xC));
    func_02075f00(arg0, M2C_FIELD(&data_02143cc0, s32 *, 0xF44), arg1);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), u8 *, 1) * 0x58) + data_021402e8);
    func_020f86e8(M2C_FIELD(arg0, s32 *, 0xC), 0, 0x400);
}
