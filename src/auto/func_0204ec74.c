/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020b818c(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_0204ec74(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91)   = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, s16 *, 0x17C) = 0;
    M2C_FIELD(data_027e000c, s16 *, 0x17E) = 0;
    M2C_FIELD(data_027e000c, s16 *, 0xA8)  = 8;
    M2C_FIELD(data_027e000c, s16 *, 0x180) = 6;
    M2C_FIELD(data_027e000c, u8 *, 8)      = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 2);
    M2C_FIELD(data_027e000c, s16 *, 0x94)  = -1;
    func_020b818c(0x72, (s32) (data_027e000c + 0x30), 0);
}
