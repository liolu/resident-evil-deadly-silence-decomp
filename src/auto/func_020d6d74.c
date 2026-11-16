/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020d87f0(void); /* extern */
s32 func_0210f1ac(void *, s32, void *); /* extern */
extern u8 data_021432a0[];
extern u8 data_02143ac0[];

s32 func_020d6d74(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_0210f1ac(data_021432a0, arg0, data_02143ac0);
    if (temp_r0 == 7) {
        return 1;
    }
    if (temp_r0 == 5) {
        func_020d87f0();
        return 0;
    }
    if (temp_r0 == 0) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
