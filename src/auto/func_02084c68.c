/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_02084c68(s32 arg0) {
    s16 var_r0;

    var_r0 = arg0 & 0xFFF;
    if (var_r0 & 0x800) {
        var_r0 = ~var_r0 & 0x7FF;
    }
    return (s32) var_r0;
}
