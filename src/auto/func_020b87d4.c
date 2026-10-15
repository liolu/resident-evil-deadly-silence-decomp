/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern s32 data_0213acf8;
extern M2C_UNK data_027e01ac;

void func_020b87d4(s32 arg0) {
    if (arg0 <= 0) {
        M2C_FIELD(&data_027e01ac, s16 *, 0x22) = (s16) arg0;
        data_0213acf8                          = arg0 << 5;
        return;
    }
    M2C_FIELD(&data_027e01ac, s16 *, 0x22) = (s16) arg0;
    data_0213acf8                          = (arg0 - 1) << 5;
}
