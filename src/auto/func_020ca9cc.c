/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020ca9cc(s32 arg0, s32 arg1) {
    s32 var_lr;

    if (arg1 == 1) {
        switch (arg0) {                             /* irregular */
            case 9:
                var_lr = 0xA;
                break;
            case 10:
                var_lr = 9;
                break;
            default:
                var_lr = arg0;
                break;
        }
        M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + (var_lr * 2)), s8 *, 0x12) = 0;
        M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + (arg0 * 2)), s8 *, 0x13)   = 0;
        M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + (arg0 * 2)), s8 *, 0x12)   = 1;
        return;
    }
    M2C_FIELD((M2C_FIELD(&data_0213b890, s32 *, 0x4C) + (arg0 * 2)), s8 *, 0x12) = 0;
}
