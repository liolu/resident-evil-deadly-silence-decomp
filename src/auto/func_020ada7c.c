/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02144c04;
extern void *data_027e000c;

s32 func_020ada7c(void) {
    u8 temp_r0;

    if (data_027e000c == &data_02144c04) {
        return (s32) (u8) (M2C_FIELD(data_027e000c, u8 *, 9) & 1);
    }
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 9);
    if ((temp_r0 == 0x21) || (temp_r0 == 0x23) || (temp_r0 == 0x2C)) {
        return 1;
    }
    return 0;
}
