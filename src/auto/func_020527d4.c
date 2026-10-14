/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_020527d4(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x92) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x92) + 1);
    M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    func_020559cc((s32) data_027e000c, 5);
}
