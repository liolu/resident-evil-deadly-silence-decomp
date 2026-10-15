/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020ecf74(s32 arg0) {
    s32 var_ip;
    s32 var_r0;

    var_r0                            = arg0;
    var_ip                            = 0;
    M2C_FIELD(var_r0, s32 *, 0x18410) = 0;
    M2C_FIELD(var_r0, s32 *, 0x18414) = 0;
    do {
        var_ip += 1;
        M2C_FIELD(var_r0, s32 *, 0xC204) = 0;
        var_r0 += 0xC208;
    } while (var_ip < 2);
}
