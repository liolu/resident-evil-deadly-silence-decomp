/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02084c40(void **, s32);
s32 func_02084c68(s32);

void func_02082514(void **arg0) {
    s32 temp_r0;

    if (M2C_FIELD(*arg0, u8 *, 0x93) != 0) {
        temp_r0 = -M2C_FIELD(arg0, s16 *, 0x20);
    } else {
        temp_r0 = M2C_FIELD(arg0, s16 *, 0x20);
    }
    func_02084c40(arg0, (s16) temp_r0);
    if (func_02084c68(M2C_FIELD(*arg0, s16 *, 0x44)) > 0x300) {
        M2C_FIELD(*arg0, u8 *, 0x92) += 1;
    }
}
