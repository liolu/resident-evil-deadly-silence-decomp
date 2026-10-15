/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02049d68(M2C_UNK);
M2C_UNK func_02053c74(M2C_UNK);

void func_02049dd8(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 var_r5;
    u32 var_r4;
    u32 var_r4_2;

    var_r5 = arg0;
    var_r4 = 2;
    do {
        temp_r0 = func_02053c74(var_r5);
        var_r5  = temp_r0;
        func_02049d68(temp_r0);
        var_r4 += 1;
    } while (var_r4 <= 6U);
    var_r4_2 = 0;
    do {
        temp_r0_2 = func_02053c74(var_r5);
        var_r5    = temp_r0_2;
        if (!(M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), u16 *, 0x184) & (1 << var_r4_2))) {
            M2C_FIELD(var_r5, s8 *, 0xB) = 0;
        } else {
            func_02049d68(temp_r0_2);
        }
        var_r4_2 += 1;
    } while (var_r4_2 < 9U);
}
