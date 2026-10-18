/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020a9b08(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_020ac214(M2C_UNK);                     /* extern */
M2C_UNK func_020adad0(u16);                         /* extern */
extern M2C_UNK data_02121f7c;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02143cc0;

void func_020ab210(void *arg0) {
    if (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 8) {
        M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x50);
    }
    if (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x20) {
        M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) - 0x50);
    }
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93)  = 1U;
        M2C_FIELD(arg0, s8 *, 0x98)  = 7;
        M2C_FIELD(arg0, s16 *, 0xA6) = 1;
        M2C_FIELD(arg0, s8 *, 0xA1)  = 5;
        func_020adad0(*((u16 *) ((s8 *) &data_02121f7c + (M2C_FIELD(arg0, u8 *, 0xA) * 2))));
        M2C_FIELD(&data_02143cc0, s8 *, 0xFE6)                              = 0xA;
        *M2C_FIELD(M2C_FIELD(&data_02143cc0, void **, 0xF44), s32 **, 0x10) = 0xA000;
        if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1) {
            func_020ac214(0);
        }
    }
    if (func_020a9b08(arg0, 2, 0x200) != 0) {
        M2C_FIELD(arg0, s8 *, 0x91)  = 0;
        M2C_FIELD(arg0, s8 *, 0x92)  = 0;
        M2C_FIELD(arg0, u8 *, 0x93)  = 0U;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0;
    }
}
