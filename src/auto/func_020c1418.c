/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207a4e0();                            /* extern */
s32 func_02095434();                                /* extern */
M2C_UNK func_020c13f8();                            /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b890;

void func_020c1418(void) {
    s32 var_r0;

    if ((M2C_FIELD(&data_0213b890, u8 *, 0x1F) != 0xFF) && (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0)) {
        var_r0 = func_02095434();
    } else {
        var_r0 = 1;
    }
    switch (var_r0) {                               /* irregular */
        case 1:
            func_0207a4e0();
            func_020c13f8();
            return;
        case 2:
            func_020c4798(3);
            return;
    }
}
