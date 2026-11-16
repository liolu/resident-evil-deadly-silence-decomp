/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020e10dc(u32, u32, u32, u32);
void func_020e102c(u32, u32, u32, u32);

void func_020e0fa8(u32 arg0, s32 arg1) {
    if (arg1 < 0x100) {
        func_020e10dc(0, 0, 0, arg0);
        return;
    }
    func_020e102c(0, 0, 0, arg0);
}
