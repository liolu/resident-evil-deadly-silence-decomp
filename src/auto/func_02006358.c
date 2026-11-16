/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213d1c0[];
extern u8 data_0213d634[];

void func_02006358(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u8 *var_ip;
    u8 *temp_r0;

    if (((arg0 >> 7) & 1) == 0) {
        var_ip = data_0213d1c0;
    } else {
        var_ip = data_0213d634;
    }
    temp_r0 = var_ip + 4 + ((arg0 & 0xF) * 8);
    if (arg1 != 0) {
        *(s32 *) temp_r0 = arg1;
    }
    *(s16 *) (temp_r0 + 4) = arg2;
    *(s16 *) (temp_r0 + 6) = arg3;
}
