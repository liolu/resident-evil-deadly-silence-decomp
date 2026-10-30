/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0018;
extern s32 data_027e0020;

s32 func_0204dbb0(void *arg0) {
    if ((s32) data_027e0018 >= (s32) ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), u8 *, 0x17E) * 0x3E8) + 0x1388)) {
        return 0;
    }
    if (data_027e0020 != 0) {
        return 0;
    }
    if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0xA) {
        return 0;
    }
    if (func_01ffd2c4(&data_02144c34, 0x200) == 0) {
        return 1;
    }
    return 0;
}
