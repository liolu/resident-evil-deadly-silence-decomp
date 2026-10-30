/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0209533c();                                /* extern */
M2C_UNK func_020b8324(s32);                         /* extern */
extern M2C_UNK data_0213b890;

void func_020c0d3c(void) {
    s32 temp_r0;
    s32 var_r4;

    var_r4  = 0;
    temp_r0 = func_0209533c();
    switch (temp_r0) {                              /* irregular */
        case 2:
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
            var_r4                                = 2;
            break;
        case 1:
            var_r4                                = 3;
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 3;
            break;
    }
    if (var_r4 != 0) {
        func_020b8324(var_r4);
    }
}
