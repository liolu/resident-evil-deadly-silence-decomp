/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 data_02144bc0[];
u8 *func_02053e90(u8);

s32 func_020b3dc8(void) {
    u8 *p;
    u8 kind;
    u16 val;

    p             = data_0213daa8;
    kind          = p[1];
    val           = *(u16 *) (p + 2);
    data_0213daa8 = p + 4;
    if (kind == 0) {
        *(u16 *) (data_02144bc0 + 0xde) = val;
    } else {
        *(u16 *) (func_02053e90(kind - 1) + 0x9a) = val;
    }
    return 1;
}
