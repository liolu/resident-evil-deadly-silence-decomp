/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 Sqrt(s32);                                      /* extern */

s32 func_02084afc(void *arg0) {
    s16 temp_r0;
    s16 temp_r2;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 0);
    temp_r0 = (s16) M2C_FIELD(temp_r1, s32 *, 0x38);
    temp_r2 = (s16) M2C_FIELD(temp_r1, s32 *, 0x30);
    if (Sqrt((temp_r2 * temp_r2) + (temp_r0 * temp_r0)) < (s32) (M2C_FIELD(arg0, s16 *, 0x10) - 0x200)) {
        return 1;
    }
    return 0;
}
