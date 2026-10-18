/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0204a278(void *, M2C_UNK);             /* extern */
void *func_02053c74(void *);                        /* extern */

void func_0204a2d4(void *arg0) {
    u8 var_r5;
    void *temp_r0;
    void *var_r6;

    var_r6                     = arg0;
    var_r5                     = 2;
    M2C_FIELD(var_r6, u8 *, 8) = (u8) (M2C_FIELD(var_r6, u8 *, 8) | 2);
    do {
        temp_r0 = func_02053c74(var_r6);
        var_r6  = temp_r0;
        func_0204a278(temp_r0, 0xFA0);
        if ((s32) M2C_FIELD(var_r6, s32 *, 0x34) < -1500) {
            M2C_FIELD(var_r6, u8 *, 8) = (u8) (M2C_FIELD(var_r6, u8 *, 8) | 0xC0);
            M2C_FIELD(var_r6, u8 *, 8) = (u8) (M2C_FIELD(var_r6, u8 *, 8) & ~0x20);
        }
        var_r5 += 1;
    } while ((u32) var_r5 < 0x10U);
}
