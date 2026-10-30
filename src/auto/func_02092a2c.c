/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020035e4(M2C_UNK, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0213e394;
extern M2C_UNK data_0213e3e8;
extern M2C_UNK data_0213f2e8;
extern M2C_UNK data_027e01ac;

void func_02092a2c(void) {
    if (M2C_FIELD(&data_0213e394, u8 *, 0x2A) != 0) {
        M2C_FIELD(&data_0213e394, u8 *, 0x2A)       = 0U;
        M2C_FIELD(&data_027e01ac, M2C_UNK **, 0x1C) = &data_0213f2e8;
        M2C_FIELD(&data_027e01ac, s16 *, 0x16)      = 0x600;
        M2C_FIELD(&data_027e01ac, s8 *, 0x18)       = 1;
    }
    if (M2C_FIELD(&data_0213e394, u8 *, 0x2E) != 0) {
        M2C_FIELD(&data_0213e394, u8 *, 0x2E) = 0U;
        func_020035e4(1, &data_0213e3e8, 0x880, 0xF00);
    }
}
