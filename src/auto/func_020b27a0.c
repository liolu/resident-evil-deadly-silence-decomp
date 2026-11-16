/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020a0600(u8 arg0);
void func_020a0658(u8 arg0);
extern u8 *data_0213daa8;

s32 func_020b27a0(void) {
    u8 *rec;
    u8 b2;
    u8 b3;

    rec           = data_0213daa8;
    b2            = rec[2];
    b3            = rec[3];
    data_0213daa8 = rec + 4;
    if (b3 != 0) {
        func_020a0658(b2);
    } else {
        func_020a0600(b2);
    }
    return 1;
}
