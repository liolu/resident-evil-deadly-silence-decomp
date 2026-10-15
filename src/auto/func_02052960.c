/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
extern void *data_027e000c;

void func_02052960(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x92)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x92) + 1);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = 4;
    func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38),
                  M2C_FIELD(data_027e000c, s32 *, 0xB0), M2C_FIELD(data_027e000c, s32 *, 0xB8) - 0x50,
                  (s32) M2C_FIELD(data_027e000c, s16 *, 0xA8));
}
