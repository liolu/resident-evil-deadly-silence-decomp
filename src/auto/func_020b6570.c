/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_020b6530(s32);
extern u8 data_0213af7c[];

s32 func_020b6570(s32 arg0) {
    s32 var_r0;

    var_r0 = data_0213af7c[0x1d];
    if (var_r0 != 0xFF) {
        var_r0 = arg0 & 0x8;
        if (var_r0 != 0) {
            func_020b6530(0);
        }
        var_r0 = arg0 & 0x10;
        if (var_r0 != 0) {
            func_020b6530(1);
        }
        var_r0 = arg0 & 0x20;
        if (var_r0 != 0) {
            var_r0 = func_020b6530(2);
        }
    }
    return var_r0;
}
