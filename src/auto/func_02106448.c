/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_01ffdcdc(s32 a, s32 b, s32 c, s32 d);
void func_02105804(s32 a, s32 b, s32 c, s32 d);
void func_02105874(s32 a, s32 b);

void func_02106448(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_02105874(arg0, -1);
    func_02105804(arg0, arg1, arg3, 0x01000000);
    if (arg3 == 0) {
        return;
    }
    while (*(volatile u32 *) (0x040000B0 + (arg0 * 3 + 2) * 4) & 0x80000000) {
    }
    func_01ffdcdc(arg0, arg1, arg2, 0xAF000001);
}
