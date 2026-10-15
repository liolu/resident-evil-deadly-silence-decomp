/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0203035c(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_0202e7f0(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x93)  = 1;
    M2C_FIELD(data_027e000c, s8 *, 0xA3)  = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98)  = 7;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
    M2C_FIELD(data_027e000c, u8 *, 0xA1)  = 5U;
    func_0203035c((s32) data_027e000c, (s32) M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
}
