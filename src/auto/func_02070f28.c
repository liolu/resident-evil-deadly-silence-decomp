/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0211e0e4;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bdcc;

u8 func_02070f28(s32 arg0) {
    s32 var_r3;

    var_r3 = 0;
    if (M2C_FIELD(&data_0213ad48, u8 *, 6) != 0) {
        var_r3 = 5;
    } else if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        var_r3 = 4;
    } else if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x10000) {
        var_r3 = 3;
    } else if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000) {
        var_r3 = 2;
    } else if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x40000) {
        var_r3 = 1;
    }
    return *(s8 *) (var_r3 + ((arg0 * 6) + (s32) &data_0211e0e4));
}