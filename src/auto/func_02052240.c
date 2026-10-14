/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_02052188(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern void *data_027e000c;

void func_02052240(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    func_02052188(-0x28, 0, 6);
    func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38), M2C_FIELD(data_027e000c, s32 *, 0xB0) - 0x28, M2C_FIELD(data_027e000c, s32 *, 0xB8) - 0x8C, 4);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = 4;
}
