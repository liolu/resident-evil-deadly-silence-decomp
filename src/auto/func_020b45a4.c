/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02017f68(s32, u8, u8, s32, s32);
extern u8 *data_0213daa8;

s32 func_020b45a4(void) {
    u8 *p;
    u8 b1;
    u8 b2;

    p             = data_0213daa8;
    b1            = p[1];
    b2            = p[2];
    data_0213daa8 = p + 4;
    func_02017f68(3, b1, b2, 0, 0);
    return 1;
}
