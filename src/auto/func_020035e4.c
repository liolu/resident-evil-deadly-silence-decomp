/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn3)(u32, u32, u32);
void func_021046d4(u32, u32);
extern Fn3 data_0211afe8[];

void func_020035e4(s32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    func_021046d4(arg1, arg3);
    data_0211afe8[arg0](arg1, arg2, arg3);
}
