/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef s32 (*Handler3)(s32, s32, s32);
extern Handler3 data_0211b008[];

s32 func_021046d4(s32, s32);

s32 func_02003630(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_021046d4(arg1, arg3);
    return data_0211b008[arg0](arg1, arg2, arg3);
}
