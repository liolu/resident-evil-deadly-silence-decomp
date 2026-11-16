/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020b1e30(u8, u8);
M2C_UNK func_020b80f4(u8, s16);
extern void *data_0213daa8;

s32 func_020b23b0(void) {
    u8 *cur;
    u8 idx;
    s16 val;

    cur           = (u8 *) data_0213daa8;
    idx           = cur[1];
    val           = (s16) func_020b1e30(idx, cur[2]);
    data_0213daa8 = (u8 *) data_0213daa8 + 4;
    func_020b80f4(idx, val);
    return 1;
}
