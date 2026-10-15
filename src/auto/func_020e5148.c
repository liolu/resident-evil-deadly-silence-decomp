/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e4c04();                                /* extern */
s32 func_020e4c0c();                                /* extern */
s32 func_020e5140();                                /* extern */

s32 func_020e5148(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
        case 0x12C:
            return func_020e5140();
        case 0xC8:
            return func_020e4c0c();
        case 0xC9:
            return func_020e4c04();
        default:
            return -1;
    }
}
