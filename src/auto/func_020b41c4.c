/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 *data_0214d068[];
extern u8 *data_0214dbec[];

s32 func_020b41c4(void) {
    u8 *p;
    u8 kind;
    u8 idx;
    u8 val;

    p             = data_0213daa8;
    kind          = p[1];
    idx           = p[2];
    val           = p[3];
    data_0213daa8 = p + 4;
    if (kind != 0) {
        if (kind == 1) {
            data_0214d068[idx][8] = val;
        }
    } else {
        data_0214dbec[idx][8] = val;
    }
    return 1;
}
