/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02088580(void);

s32 func_0207f61c(void) {
    s32 temp_r0;
    u8 var_r3;
    u8 var_r4;
    void *temp_r2;

    var_r4  = 0;
    temp_r0 = func_02088580();
    var_r3  = 0;
    do {
        temp_r2 = M2C_FIELD(((var_r3 * 0x1E8) + temp_r0), void **, 0x130);
        if ((temp_r2 != NULL) && (M2C_FIELD(temp_r2, u8 *, 9) == 0xB)) {
            var_r4 += 1;
        }
        var_r3 += 1;
    } while ((u32) var_r3 < 0x10U);
    return (s32) var_r4;
}
