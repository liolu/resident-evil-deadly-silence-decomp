/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b2b4[];
void func_020f2a90(s32, s32, s32);
void func_021060e8(s32, void *, s32);

void func_02076928(s32 arg0, u8 *arg1) {
    volatile s32 sp0;
    s32 temp_r3;
    u8 *temp_r4;

    temp_r3 = *(s32 *) (arg1 + 0x14);
    sp0     = 0;
    temp_r4 = arg1 + temp_r3;
    func_021060e8(sp0, temp_r4, *(s32 *) (arg1 + 4) - temp_r3);
    func_020f2a90(*(s32 *) (data_0213b2b4 + 0xF4), arg0, (s32) temp_r4 - arg0);
}
