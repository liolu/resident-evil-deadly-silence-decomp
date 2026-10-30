/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02091014(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020adad0(M2C_UNK);                     /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;

void func_0204f264(void) {
    if ((func_02091014(0, 0x80, 5) != 0) || ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0)) {
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD4) = 1;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD5) = 0;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD6) = 0;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD7) = 0;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 0;
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) & ~0xA);
        func_020adad0(0x8000);
    }
}
