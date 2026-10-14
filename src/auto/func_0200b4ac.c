/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern s32 data_02137298;

s32 func_0200b4ac(s32 arg0) {
    u16 var_lr;
    u8 var_ip;

    var_lr = 0;
    var_ip = 0;
    do {
        if (arg0 == M2C_FIELD((data_02137298 + (var_ip << 6)), u8 *, 0x1451)) {
            var_lr |= 1 << var_ip;
        }
        var_ip += 1;
    } while ((u32) var_ip < 0x10U);
    return (s32) var_lr;
}
