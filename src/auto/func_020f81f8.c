/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020f7d04();                            /* extern */
M2C_UNK func_020fe764();              /* extern */
s32 func_02100b0c();                             /* extern */
s32 func_02100b54();                       /* extern */

void func_020f81f8(s32 arg0, s32 arg1) {
    u8 sp0[64];

    func_020f7d04();
    *(s32 *) 0x04000440 = 0;
    *(s32 *) 0x04000444 = 0;
    *(s32 *) 0x04000454 = 0;
    if (arg0 != 0) {
        do {

        } while (func_02100b54(sp0) != 0);
        func_020fe764(sp0, arg0);
    }
    if (arg1 != 0) {
        do {

        } while (func_02100b0c(arg1) != 0);
    }
    *(s32 *) 0x04000448     = 1;
    *(M2C_UNK *) 0x04000440 = 2;
}
