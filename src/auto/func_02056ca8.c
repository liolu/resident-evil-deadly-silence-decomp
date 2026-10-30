/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02056fb0(M2C_UNK);                         /* extern */
s32 func_0205865c(M2C_UNK);                         /* extern */
extern u16 data_0213ad98;
extern M2C_UNK data_0213bdcc;

s32 func_02056ca8(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x01000000;
    if (var_r0 != 0) {
        var_r0 = 0x302;
        if (data_0213ad98 == 0x302) {
            var_r0 = func_0205865c(0);
            if (var_r0 != 0) {
                var_r0 = func_02056fb0(0);
            }
        }
    }
    return var_r0;
}
