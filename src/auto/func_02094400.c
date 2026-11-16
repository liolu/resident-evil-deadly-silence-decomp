/* compiler: 1.2/sp2p3 */
#include "m2c.h"
extern u8 data_0213bb18[];
extern u8 data_0213cda0[];

u32 func_02094400(void) {
    u8 *base = data_0213cda0;
    u32 v    = (u32) (*(s32 *) (data_0213bb18 + 0x1FC) << 0x1F) >> 0x1F;
    if (v == 0) {
        v          = 0xFF;
        base[0x49] = 0xFF;
        base[0x48] = 0xFF;
        base[0x46] = 0xFF;
        base[0x44] = 0xFF;
    }
    return v;
}
