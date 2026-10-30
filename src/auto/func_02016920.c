/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201697c();                            /* extern */
M2C_UNK func_02016a94(void *);                      /* extern */

void func_02016920(void *arg0) {
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) >= 0) {
        M2C_FIELD(arg0, s16 *, 8)    = 0;
        M2C_FIELD(arg0, s16 *, 0xA)  = 0;
        M2C_FIELD(arg0, s16 *, 0xC)  = 0;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
        M2C_FIELD(arg0, s16 *, 0x12) = 0;
        M2C_FIELD(arg0, s16 *, 0x14) = 0;
        M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (0 - (M2C_FIELD(arg0, s16 *, 0x2A) + M2C_FIELD(arg0, s32 *, 0x48)));
        func_0201697c(arg0);
        func_02016a94(arg0);
    }
}
