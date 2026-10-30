/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02078240();                            /* extern */
M2C_UNK func_020b80e4();                            /* extern */
M2C_UNK func_020d9090();                            /* extern */
M2C_UNK func_020ff278();                            /* extern */
M2C_UNK func_020ff2c4();                            /* extern */
s32 func_0210ad94();                         /* extern */
M2C_UNK func_0210aea4();   /* extern */
extern M2C_UNK data_0213ad30;

void func_02078384(void) {
    if (M2C_FIELD(&data_0213ad30, u8 *, 9) != 0) {
        func_020b80e4();
        func_020d9090();
        func_02078240();
        func_020ff2c4();
        *(s32 *) 0x04001000 &= ~0x10000;
        func_0210ad94(0);
        func_0210aea4(0xC, 0, 0);
        func_02078240();
        do {

        } while (func_0210ad94(1) == 0);
        func_02078240();
        *(u16 *) 0x04000304 = (*(u16 *) 0x04000304 & 0xFFFFFDF1) | 0x20E;
        func_020ff278();
        *(M2C_UNK *) 0x04001000 = (s32) (*(M2C_UNK *) 0x04001000 | 0x10000);
    }
}
