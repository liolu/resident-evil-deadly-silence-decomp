/* compiler: 1.2/sp2p3 */
#include "m2c.h"

u64 func_0211851c(u8, s32);
extern M2C_UNK data_0213b890;

void func_020cb2fc(void) {
    u8 var_r8;
    u64 temp;

    var_r8 = 0;
    do {
        temp = func_0211851c(M2C_FIELD(&data_0213b890, u8 *, 0x1F), 2);
        if ((u32) (temp >> 32) == 0) {
            M2C_FIELD(&data_0213b890, u8 **, 0x4C)[var_r8] = 1;
        } else {
            M2C_FIELD(&data_0213b890, u8 **, 0x4C)[var_r8] = 0;
        }
        var_r8 += 1;
    } while ((u32) var_r8 < 5U);
}
