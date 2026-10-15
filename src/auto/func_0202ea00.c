/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0203035c(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_02137338;
extern void *data_027e000c;

void func_0202ea00(void) {
    if (M2C_FIELD(data_027e000c, u8 *, 0x93) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x93)  = 1U;
        M2C_FIELD(data_027e000c, s8 *, 0xA3)  = 0;
        M2C_FIELD(data_027e000c, u8 *, 0xA1)  = 1U;
        M2C_FIELD(data_027e000c, s8 *, 0x98)  = 7;
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0;
        M2C_FIELD(data_02137338, s16 *, 0xE)  = 0;
        func_0203035c((s32) data_027e000c, (s32) M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
    }
    func_0209109c(1, 0x200, 5);
}
