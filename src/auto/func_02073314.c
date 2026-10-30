/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0209089c();                            /* extern */
extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213bd18;

void func_02073314(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x15) = (u8) (M2C_FIELD(arg0, u8 *, 0x15) - 1);
    if (M2C_FIELD(arg0, u8 *, 0x15) == 0) {
        M2C_FIELD(arg0, s8 *, 1)    = 1;
        M2C_FIELD(arg0, u8 *, 0x15) = 3U;
        func_0206fcf8(0, 0, 0, 0x40);
        func_0209089c();
        M2C_FIELD(&data_0213af7c, s16 *, 0x28) = 0x49;
        M2C_FIELD(&data_0213af7c, s8 *, 0x27)  = 0;
        M2C_FIELD(&data_0213af7c, s8 *, 0x26)  = 0;
        M2C_FIELD(&data_0213bd18, s16 *, 4)    = 0;
        M2C_FIELD(&data_0213bd18, s16 *, 6)    = 0;
    }
}
