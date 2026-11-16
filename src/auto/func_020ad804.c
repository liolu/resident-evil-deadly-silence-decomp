/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02144c04;
extern M2C_UNK data_02147cc0;

s32 func_020ad804(void) {
    u8 *p;

    p = (u8 *) &data_02144c04;
    if (M2C_FIELD(p, u8 *, 0x96) != 0) {
        return 0;
    }
    if ((s32) M2C_FIELD(p, s16 *, 0x94) < 0) {
        return 0;
    }
    if (M2C_FIELD(p, u8 *, 0x90) != 1) {
        return 0;
    }
    if ((M2C_FIELD(&data_02147cc0, u8 *, 0x542) | M2C_FIELD(&data_02147cc0, u8 *, 0x543)) != 0) {
        return 0;
    }
    if (!(M2C_FIELD(&data_0213bdcc, u32 *, 0x44) & 0x01000900)) {
        return 1;
    }
    return 0;
}
