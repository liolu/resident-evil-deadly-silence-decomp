/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02085188(M2C_UNK, M2C_UNK);

void func_02085144(s32 arg0) {
    s32 var_r5;

    var_r5 = 0;
    do {
        if (M2C_FIELD(((var_r5 * 0x1E8) + arg0), s32 *, 0x130) != 0) {
            func_02085188(arg0, var_r5);
        }
        var_r5 = (s32) (u8) (var_r5 + 1);
    } while ((u32) var_r5 < 0x10U);
}
