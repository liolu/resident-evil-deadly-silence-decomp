/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern void *data_02137338;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_0202eba8(void) {
    if ((M2C_FIELD(data_02137338, s16 *, 6) != 0) && ((s32) data_027e0018 < 0x2328)) {
        M2C_FIELD(data_027e000c, u8 *, 0xA) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) & ~0x10);
    }
    if ((s32) data_027e0018 < 0xFA0) {
        M2C_FIELD(data_027e000c, u8 *, 0xA) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) & ~0x10);
    }
}
