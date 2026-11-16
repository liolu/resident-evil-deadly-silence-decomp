/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020062ac(u8, s8 *);
extern M2C_UNK data_0213b8c0;
extern M2C_UNK data_0213b8f4;

typedef struct {
    s8 f0;
    u8 pad1;
    u8 f2;
    u8 f3;
    s16 f4;
    s16 f6;
    u16 f8;
} Tmp10;

void func_02098820(s32 arg0, s32 arg1, s8 arg2, s16 arg3, u16 arg4, u8 arg5, u8 arg6) {
    Tmp10 loc;
    u8 var_r0;

    if (arg0 != 0) {
        var_r0 = *(u8 *) ((u8 *) &data_0213b8f4 + arg1);
    } else {
        var_r0 = *(u8 *) ((u8 *) &data_0213b8c0 + arg1);
    }
    loc.f2 = arg6;
    loc.f4 = 0;
    loc.f3 = arg5;
    loc.f6 = arg3;
    loc.f8 = arg4;
    loc.f0 = arg2;
    func_020062ac(var_r0, (s8 *) &loc);
}
