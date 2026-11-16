/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_01ffdc68(s32, s32, s32, s32);
void func_02105804(s32, s32, s32, s32);

s32 func_02105b9c(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    volatile u32 *reg;
    s32 temp_r0;

    if (arg3 == 0) {
        return arg0;
    }
    func_02105804(arg0, arg1, arg3, 0);
    reg = (volatile u32 *) (0x040000B0 + ((arg0 * 3 + 2) * 4));
    do {
    } while (*reg & 0x80000000);
    func_01ffdc68(arg0, arg1, arg2, (arg3 >> 1) | 0x80000000);
    do {
        temp_r0 = *reg & 0x80000000;
    } while (temp_r0 != 0);
    return temp_r0;
}
