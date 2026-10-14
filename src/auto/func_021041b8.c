/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_021040b0(void);
M2C_UNK func_021040e4(void);
M2C_UNK func_02104230(void);

extern s32 data_02136ba0;

s32 func_021041b8(void) {
    s32 temp_r4;
    s32 var_r2;

    if (data_02136ba0 == -1) {
        temp_r4 = func_021040e4();
        if (func_02104230() != 0) {
            var_r2 = temp_r4 | 0x10000000;
        } else if (func_021040b0() != 0) {
            var_r2 = temp_r4 | 0x40000000;
        } else if (temp_r4 & 0x01000000) {
            var_r2 = temp_r4 | 0x20000000;
        } else {
            var_r2 = temp_r4 | 0x80000000;
        }
        data_02136ba0 = var_r2 | *(u16 *)0x027FFFFA;
    }
    return data_02136ba0;
}
