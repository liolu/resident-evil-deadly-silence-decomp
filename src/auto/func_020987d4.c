/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b2b4[];
void func_02098820(s32, s32, s32, s32, s32, s32, s32);

void func_020987d4(s32 arg0, s32 arg1) {
    u32 flags;
    u8 flag;

    flags = *(u16 *) (data_0213b2b4 + 0xa4);
    flag  = (flags >> 4) & 1;
    func_02098820(1, 0, 2, arg0, arg1, flag, 0);
}
