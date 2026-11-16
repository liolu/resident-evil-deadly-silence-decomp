/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02053b0c(u8);                          /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02147cc0;
extern M2C_UNK data_0214813e;

void func_02053bec(void) {
    u8 var_r7;
    u8 var_r6;
    u8 temp_r5;
    void *temp_r0;
    u8 temp_r1;

    var_r6  = M2C_FIELD(&data_02147cc0, u8 *, 0x47C);
    var_r7  = 0;
    temp_r5 = ((u8 *) &data_0214813e)[var_r6 * 4];
    goto cond;
body:
    temp_r0 = (u8 *) &data_02143cc0 + (var_r6 * 4);
    temp_r0 = temp_r0 + 0x4000;
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 0x47C);
    var_r7  = var_r6;
    var_r6  = M2C_FIELD(temp_r0, u8 *, 0x47F);
    if (temp_r1 == 2) {
        func_02053b0c(var_r7);
    }
cond:
    if (var_r7 != temp_r5) {
        goto body;
    }
}
