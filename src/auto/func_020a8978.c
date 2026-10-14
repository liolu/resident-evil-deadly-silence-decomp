/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020a9b08(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_020ad928(M2C_UNK);                     /* extern */
M2C_UNK func_020adad0(s32);                         /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;

void func_020a8978(void *arg0) {
    s32 temp_r5;

    if (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 8) {
        M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x50);
    }
    if (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x20) {
        M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) - 0x50);
    }
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        M2C_FIELD(arg0, s8 *, 0xA3) = 0;
        M2C_FIELD(arg0, s16 *, 0xA6) = 1;
        M2C_FIELD(arg0, s8 *, 0xA1) = 5;
        func_020adad0(0x803B);
    }
    temp_r5 = *M2C_FIELD(M2C_FIELD(&data_02143cc0, void **, 0xF44), s32 **, 0x10);
    if (temp_r5 == 0x9000) {
        M2C_FIELD(arg0, s8 *, 0xA) = 0;
    } else if (temp_r5 == 0x10000) {
        func_020ad928(1);
    }
    if ((temp_r5 >= 0xC000) && (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x3C)) {
        if (temp_r5 < 0x10000) {
            func_020ad928(1);
        }
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, u8 *, 0x93) = 0U;
    }
    if (func_020a9b08(arg0, 0, 0x400) != 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, u8 *, 0x93) = 0U;
    }
}
