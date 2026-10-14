/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02075f00(void *, s32, M2C_UNK);        /* extern */
M2C_UNK func_020f8678(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020f86e8(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 data_021402e8;
extern void *data_027e000c;

void func_020bb8c8(void) {
    void *temp_r4;

    temp_r4 = M2C_FIELD(data_027e000c, void **, 0x188);
    func_020f86e8(M2C_FIELD(temp_r4, s32 *, 0xC), 0, 0x400);
    func_020f8678(M2C_FIELD(temp_r4, s32 *, 0xC), 0, 0xF);
    func_02075f00(temp_r4, M2C_FIELD(data_027e000c, s32 *, 0), 0);
    M2C_FIELD(temp_r4, s32 *, 0x54) = (s32) ((M2C_FIELD(M2C_FIELD(temp_r4, void **, 0x14), u8 *, 1) * 0x58) + data_021402e8);
}
