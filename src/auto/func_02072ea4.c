/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02072d94();                                /* extern */
M2C_UNK func_02072dc8(s32, s32);                    /* extern */
M2C_UNK func_020abd9c(M2C_UNK);                     /* extern */
s32 func_020add50();                                /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;
extern M2C_UNK *data_027e000c;

void func_02072ea4(void) {
    data_027e000c = &data_02144c04;
    func_02072dc8(M2C_FIELD(&data_02143cc0, s32 *, 0xF44), func_020add50());
    if (func_02072d94() != 0) {
        func_020abd9c(3);
    }
}
