/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02006390(u8);
M2C_UNK func_020064dc(s32, M2C_UNK);
extern s8 data_0213d1c0;
extern s8 data_0213d634;

void func_020063d0(s32 arg0) {
    s8 *var_r0;
    u8 var_r5;

    func_020064dc(arg0, 0);
    var_r0  = (arg0 == 0) ? &data_0213d1c0 : &data_0213d634;
    var_r5  = 0;
    *var_r0 = (s8) var_r5;
    do {
        func_02006390((u8) ((arg0 << 7) | var_r5));
        var_r5 += 1;
    } while ((u32) var_r5 < 8U);
}
