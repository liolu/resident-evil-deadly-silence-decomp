/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_02137898;
extern u8 *data_0213789c;
void func_0208dddc(void);

s32 func_0208d908(void) {
    s32 var_r0;
    u8 t;

    t      = data_02137898[5];
    var_r0 = *(s32 *) (data_0213789c + 0x30);
    if (t == 0) {
        func_0208dddc();
        var_r0           = data_02137898[5] + 1;
        data_02137898[5] = (u8) var_r0;
    }
    return var_r0;
}
