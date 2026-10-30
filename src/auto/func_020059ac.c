/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020055f8();                            /* extern */
M2C_UNK func_020ded2c();                            /* extern */
M2C_UNK func_020e605c();                            /* extern */
M2C_UNK func_020ed938();                            /* extern */
extern s32 data_02137264;

void func_020059ac(void) {
    if (data_02137264 != 0) {
        func_020055f8();
        func_020ed938();
        func_020ded2c();
        func_020e605c();
        data_02137264 = 0;
    }
}
