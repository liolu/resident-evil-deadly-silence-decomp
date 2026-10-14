/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_0208b7f4(s32 arg0) {
    s32 var_lr;
    u8 temp_r0;
    void *temp_ip;

    temp_ip = M2C_FIELD(arg0, void **, 0x2B4);
    var_lr = 0;
    if (((s32) M2C_FIELD(arg0, s16 *, 0x28A) > (s32) (M2C_FIELD(temp_ip, u8 *, 2) + 3)) && (M2C_FIELD(arg0, u8 *, 0x4BC) != 0)) {
        temp_r0 = M2C_FIELD(temp_ip, u8 *, 3);
        if ((temp_r0 != 0) && (temp_r0 != 5)) {
            var_lr = 1;
        }
    }
    return var_lr;
}
