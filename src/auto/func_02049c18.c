/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02047eb0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02047ff0(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02049c18(void) {
    if (M2C_FIELD(data_027e000c, u8 *, 0x93) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, u8 *, 0xA1) = 0U;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 0x1F;
        func_02047ff0((s32) data_027e000c, (s32) M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
    }
    func_02047eb0((s32) data_027e000c, 1, 0x80, 7);
}
