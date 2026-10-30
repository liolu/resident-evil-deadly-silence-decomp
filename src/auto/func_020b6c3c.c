/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b6b5c();                                /* extern */
extern M2C_UNK data_021236b4;

u8 func_020b6c3c(u32 arg0) {
    u8 var_r0;
    u8 var_r0_2;

    if (arg0 < 0x20U) {
        switch (arg0) {                             /* irregular */
            case 6:
                if (func_020b6b5c() != 0) {
                    var_r0 = 0x5B;
                } else {
                    var_r0 = 0x5A;
                }
                return var_r0;
            case 10:
                if (func_020b6b5c() != 0) {
                    var_r0_2 = 0x5F;
                } else {
                    var_r0_2 = 0x5E;
                }
                return var_r0_2;
            default:
                return ((s8 *) &data_021236b4)[arg0];
        }
    } else {
        return 0U;
    }
}
