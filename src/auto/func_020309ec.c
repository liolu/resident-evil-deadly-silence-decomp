/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0203035c(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020304c8(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_020309ec(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    M2C_FIELD(data_027e000c, u8 *, 0xA1) = 0xCU;
    func_0203035c((s32) data_027e000c, (s32) M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
    func_020304c8(2, 0);
}
