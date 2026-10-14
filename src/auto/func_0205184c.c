/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0205126c(s32, s32, s32, s32, s32);     /* extern */
extern void *data_027e000c;

void func_0205184c(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, u16 *, 0xA8) = 4U;
    func_0205126c(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38), M2C_FIELD(data_027e000c, s32 *, 0xB0), M2C_FIELD(data_027e000c, s32 *, 0xB8) + 0x50, (s32) M2C_FIELD(data_027e000c, u16 *, 0xA8));
}
