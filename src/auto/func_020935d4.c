/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02093504(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020935d4(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r1;

    switch (arg1) {                                 /* irregular */
    case 0:
        var_r0 = 0x4210;
        var_r1 = 0x1F;
        break;
    case 1:
        var_r0 = 0x4210;
        var_r1 = 0x3FF;
        break;
    case 2:
        var_r0 = 0x6118;
        var_r1 = 0x7C1F;
        break;
    default:
        var_r0 = 0x4210;
        var_r1 = 0;
        break;
    }
    M2C_FIELD(arg0, s16 *, 0x50) = (s16) func_02093504(var_r0, var_r1, M2C_FIELD(arg0, u16 *, 0x172) * 0xD);
}
