/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213bdcc;
extern void *data_027e000c;

void func_02051974(void) {
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x20000) {
        return;
    }
    M2C_FIELD(data_027e000c, u8 *, 0xA) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) | 0x20);
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
}
