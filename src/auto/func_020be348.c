/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02074d40();                                /* extern */
extern M2C_UNK data_0213bf2e;
extern M2C_UNK data_0213bf2f;

void func_020be348(s8 arg0, s8 arg1) {
    s32 temp_r0;

    temp_r0 = func_02074d40();
    if (temp_r0 != -1) {
        *((u8 *) ((s8 *) &data_0213bf2e + (temp_r0 * 2))) = arg0;
        *((u8 *) ((s8 *) &data_0213bf2f + (temp_r0 * 2))) = arg1;
    }
}
