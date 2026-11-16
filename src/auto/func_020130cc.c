/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213ad2c;
s32 func_020111fc(void *);

s32 func_020130cc(u8 *arg0, u8 *arg1) {
    *(s32 *) (arg1 + 0)    = 0;
    *(s32 *) (arg1 + 4)    = 0;
    *(s32 *) (arg1 + 8)    = 0;
    *(s16 *) (arg1 + 0xC)  = 0;
    *(s16 *) (arg1 + 0xE)  = 0;
    *(s16 *) (arg1 + 0x10) = 0;
    arg1[0xE4]             = 0x28;
    *(s16 *) (arg1 + 0x12) = 0x3E8;
    if (data_0213ad2c[9] == 2) {
        *(s32 *) (arg1 + 0)    = -0x320;
        arg1[0xE4]             = 0xA0;
        *(s16 *) (arg1 + 0x14) = 0x10;
        *(s16 *) (arg1 + 0xE)  = -0x2C00;
        arg0[5]                = 6;
    }
    return func_020111fc(arg1);
}
