/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 data_02144bc0;

s32 func_020b3d84(void) {
    u8 *p;
    s16 v;
    s32 t;

    p                                = data_0213daa8;
    t                                = p[1];
    v                                = *(s16 *) (&data_02144bc0 + 0xde);
    data_0213daa8                    = p + 2;
    *(s16 *) (&data_02144bc0 + 0xde) = v + t;
    return 1;
}
