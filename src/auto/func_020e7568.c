/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_020e8898(s32);                         /* extern */

void func_020e7568(void *arg0) {
    s32 var_r4;

    var_r4 = 0;
    if ((s32) M2C_FIELD(arg0, s8 *, 3) <= 0) {
        return;
    }
    do {
        func_020e8898(M2C_FIELD((arg0 + (var_r4 * 4)), s32 *, 0x48));
        var_r4 += 1;
    } while (var_r4 < (s32) M2C_FIELD(arg0, s8 *, 3));
}
