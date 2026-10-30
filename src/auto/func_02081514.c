/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02082314(void *);                          /* extern */
M2C_UNK func_020823b4(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02083d28();                            /* extern */

void func_02081514(void *arg0) {
    void *temp_ip;

    M2C_FIELD(arg0, s32 *, 0x1CC) = (s32) (M2C_FIELD(arg0, s32 *, 0x1CC) - 1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x1CC) <= 0) {
        func_02083d28(arg0);
        M2C_FIELD(arg0, u8 *, 0xD) = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~4);
    }
    if ((func_02082314(arg0) != 0) && ((s32) M2C_FIELD(arg0, s32 *, 0x1CC) <= 0)) {
        temp_ip                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_ip, u8 *, 0x92) = (u8) (M2C_FIELD(temp_ip, u8 *, 0x92) + 1);
        func_020823b4(arg0, 0x16, 0, 0);
        M2C_FIELD(arg0, u8 *, 7) = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
}
