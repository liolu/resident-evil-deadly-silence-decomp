/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_020c1f80(s8 *arg0) {
    s8 temp_r1;

    temp_r1 = *arg0;
    if ((s32) temp_r1 < 0) {
        *arg0 = temp_r1 + 1;
        if ((s32) *arg0 >= 0) {
            *arg0 = -0x80;
        }
        return;
    }
    if ((s32) temp_r1 > 0) {
        *arg0 = temp_r1 - 1;
    }
}
