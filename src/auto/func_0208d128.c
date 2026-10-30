/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208850c();                            /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_02144bc0;

void func_0208d128(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x17A) == 0) {
        M2C_FIELD(arg0, s16 *, 0x94) = (s16) M2C_FIELD(&data_02144bc0, s16 *, 0xD8);
        if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && ((s32) M2C_FIELD(arg0, s16 *, 0x94) < 0)) {
            M2C_FIELD(arg0, s8 *, 0x324)  = 2;
            M2C_FIELD(arg0, s16 *, 0x378) = 0;
            func_0208850c();
        }
    }
}
