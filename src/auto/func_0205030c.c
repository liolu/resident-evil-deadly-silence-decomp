/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_020ad804();                                /* extern */
extern M2C_UNK data_02144c34;

void func_0205030c(void *arg0) {
    s32 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0xA) != 2) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        return;
    }
    temp_r1 = M2C_FIELD(arg0, s32 *, 0x17C);
    if (temp_r1 > 0xFA0) {
        M2C_FIELD(arg0, u16 *, 0x190) = 0U;
        M2C_FIELD(arg0, s16 *, 0x180) = 0;
        return;
    }
    if (temp_r1 <= 0xC44) {
        if (M2C_FIELD(arg0, u16 *, 0x190) == 0) {
            if (func_01ffd2c4(&data_02144c34, 0x200) == 0) {
                M2C_FIELD(arg0, u16 *, 0x190) = 2U;
            }
            if (func_01ffd2c4(&data_02144c34, 0x600) != 0) {
                M2C_FIELD(arg0, u16 *, 0x190) = 1U;
            }
            return;
        }
        if (func_020ad804() != 0) {
            M2C_FIELD(arg0, s16 *, 0x18E) = (s16) M2C_FIELD(arg0, s16 *, 0x44);
            M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + ((M2C_FIELD(arg0, u16 *, 0x190) - 1) << 0xB));
            if (func_01ffd2c4(&data_02144c34, 0x200) == 0) {
                M2C_FIELD(arg0, s8 *, 0x91) = 0;
                M2C_FIELD(arg0, u8 *, 0xA)  = 5U;
            }
            M2C_FIELD(arg0, s16 *, 0x44) = (s16) M2C_FIELD(arg0, s16 *, 0x18E);
        }
    }
}
