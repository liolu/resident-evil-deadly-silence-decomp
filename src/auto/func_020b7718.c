/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0200d410(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213abc4;

void func_020b7718(s32 arg0, s32 arg1) {
    s32 var_r5;

    var_r5 = 0;
    do {
        func_0200d410((s32) (u16) M2C_FIELD(((arg0 * 0xC) + (s32) &data_0213abc4), s32 *, 0xE8), var_r5, arg1);
        var_r5 = (s32) (u8) (var_r5 + 1);
    } while ((u32) var_r5 < 2U);
}
