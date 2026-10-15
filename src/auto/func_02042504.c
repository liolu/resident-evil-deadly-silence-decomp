/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02143cc0;
extern s32 data_027e0018;

void func_02042504(void *arg0) {
    if ((s32) data_027e0018 <= 0x2710) {
        return;
    }
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFD6) == 0xD) {
        M2C_FIELD(arg0, u8 *, 0x93)  = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x82;
    }
}
