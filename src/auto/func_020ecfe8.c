/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ed0b0(M2C_UNK);
M2C_UNK func_020ed670(M2C_UNK);
M2C_UNK func_020ed69c(M2C_UNK);
void func_020ed6dc(M2C_UNK);
void func_020ed778(M2C_UNK, M2C_UNK);

s32 func_020ecfe8(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_020ed670(arg0 + 0xC);
    if (func_020ed69c(arg0 + 0x10) != 4) {
        if (temp_r4 == 1) {
            func_020ed6dc(arg0);
            func_020ed778(arg0 + 0x10, 4);
            return 1;
        }
        if (temp_r4 == 3) {
            func_020ed0b0(arg0);
        }
        goto block_5;
    }
block_5:
    if (func_020ed69c(arg0 + 0x10) == 4) {
        return 1;
    }
    return 0;
}
