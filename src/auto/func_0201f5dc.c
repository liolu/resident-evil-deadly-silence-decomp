/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_02144c34;

void func_0201f5dc(void *arg0) {
    if (func_02075738(0, 0x400) != 0) {
        M2C_FIELD(arg0, u16 *, 0x198) = (u16) (M2C_FIELD(arg0, u16 *, 0x198) & ~0x20);
        M2C_FIELD(arg0, u8 *, 8)      = (u8) (M2C_FIELD(arg0, u8 *, 8) & ~2);
        if (func_01ffd2c4(&data_02144c34, 0x200) == 0) {
            M2C_FIELD(arg0, u8 *, 0x91) = (u8) (M2C_FIELD(arg0, u8 *, 0x91) + 1);
            func_020559cc(arg0, 3);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x91) = 1U;
        M2C_FIELD(arg0, s8 *, 0x92) = 1;
        func_020559cc(arg0, 0xA);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x82;
    }
}
