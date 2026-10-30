/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020559cc(void *, u8);                  /* extern */
extern M2C_UNK data_02143cc0;

void func_020206a4(void *arg0) {
    if (((s32) M2C_FIELD(arg0, s32 *, 0x17C) <= 0x1194) || (M2C_FIELD(&data_02143cc0, s32 *, 0xFD4) == 0x140301)) {
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
        func_020559cc(arg0, (u8) (M2C_FIELD(arg0, u8 *, 0xA1) + 1));
        M2C_FIELD(arg0, s8 *, 0xA2)   = 0;
        M2C_FIELD(arg0, s8 *, 0xA3)   = 0;
        M2C_FIELD(arg0, s8 *, 0x98)   = 0xF;
        M2C_FIELD(arg0, s16 *, 0x190) = 0;
    }
}
