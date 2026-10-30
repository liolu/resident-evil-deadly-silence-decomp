/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020133d8();                                /* extern */
extern M2C_UNK data_0213ae4c;

s32 func_020d3dd0(void) {
    s32 temp_r0;

    if (M2C_FIELD(&data_0213ae4c, u16 *, 8) != 1) {
        return 0;
    }
    temp_r0 = func_020133d8();
    switch (temp_r0) {                              /* irregular */
        case -1:
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 0;
    }
}
