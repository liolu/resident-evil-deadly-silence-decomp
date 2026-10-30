/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ac39c(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_0213db04;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;

void func_020ac488(void) {
    void *temp_r1;

    switch (M2C_FIELD(&data_02143cc0, u8 *, 0xFD7)) { /* irregular */
        case 0:
            M2C_FIELD(&data_02143cc0, s8 *, 0xFE7) = 0;
            M2C_FIELD(&data_02143cc0, u8 *, 0xFE5) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xFE5) - 5);
            M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) = 1U;
            M2C_FIELD(&data_02143cc0, s8 *, 0xFDC) = 3;
            temp_r1                                = M2C_FIELD(M2C_FIELD(&data_02143cc0, void **, 0xF44), void **, 0x10);
            M2C_FIELD(temp_r1, s32 *, 0)           = (s32) (M2C_FIELD(M2C_FIELD(temp_r1, void **, 8), u16 *, 4) << 0xC);
        /* fallthrough */
        case 1:
            M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) + func_020ac39c(2, 0x400));
            return;
        case 2:
            M2C_FIELD(&data_02143cc0, s8 *, 0xFD4) = 1;
            M2C_FIELD(&data_02143cc0, s8 *, 0xFD5) = 0;
            M2C_FIELD(&data_02143cc0, s8 *, 0xFD6) = 0;
            M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) = 0U;
            func_020b3a24(&data_0213db04, M2C_FIELD(&data_02144cc0, u8 *, 3));
            return;
    }
}
