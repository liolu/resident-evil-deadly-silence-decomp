/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_02074ef0(u8);
extern u8 *data_0213daa8;
extern M2C_UNK data_02147cc0;

s32 func_020b43cc(void) {
    u8 t;
    u32 idx;
    u8 *p;

    p                                                        = data_0213daa8;
    t                                                        = p[1];
    data_0213daa8                                            = p + 2;
    idx                                                      = (u8) func_02074ef0(t);
    M2C_FIELD(&data_02147cc0, u8 **, 0x538)[idx * 2]         = 0;
    (M2C_FIELD(&data_02147cc0, u8 **, 0x538) + (idx * 2))[1] = 0;
    return 1;
}
