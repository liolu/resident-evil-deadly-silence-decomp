/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02086df0();                            /* extern */
s32 func_02087278();                                /* extern */
M2C_UNK func_02087470();                            /* extern */
M2C_UNK func_02088438();                            /* extern */
extern s32 data_02137504;

void func_0208752c(void) {
    if ((s32) data_02137504 > 1) {
        func_02087470();
        if (func_02087278() != 0) {
            func_02086df0();
            func_02088438();
        }
    }
}
