/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void func_02053c54(s32);
extern void func_020f4384(s32);
extern void func_021061d8(s32 *, s32, s32);

s32 func_02085188(u8 *arg0, s32 arg1) {
    s32 **temp_r4;
    s32 temp_r0;

    temp_r4 = (s32 **) (arg0 + 0x130 + arg1 * 0x1E8);
    temp_r0 = **temp_r4;
    if (temp_r0 != 0) {
        func_020f4384(temp_r0 + 0x20);
    }
    func_02053c54((s32) *temp_r4);
    func_021061d8((s32 *) temp_r4, 0, 0x1E8);
    return 1;
}
