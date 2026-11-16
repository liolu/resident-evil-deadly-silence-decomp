/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_020ca464(s32, u8);
extern M2C_UNK data_0213b890;

s8 func_020ca49c(s32 arg0) {
    u8 *p;
    s32 var_r5;
    s32 idx;
    u8 var_r1;

    var_r5 = 1;
    idx    = 1;
    p      = *(u8 **) ((u8 *) &data_0213b890 + 0x4C);
    var_r1 = p[1];
    do {
        var_r1 = (u8) func_020ca464(idx, var_r1);
        p      = *(u8 **) ((u8 *) &data_0213b890 + 0x4C);
        if (arg0 == (p + var_r1)[2]) {
            return (s8) var_r1;
        }
        if (var_r1 == p[1]) {
            var_r5 = 0;
        }
    } while (var_r5 != 0);
    return -1;
}
