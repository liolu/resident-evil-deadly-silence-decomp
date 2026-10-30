/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d2040();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020d274c(void) {
    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* irregular */
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD4) = 0;
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD0) = 0;
            M2C_FIELD(&data_0213b890, u8 *, 0x1F)                            = 0x2DU;
            M2C_FIELD(&data_0213b890, u8 *, 0x22)                            = 1U;
            return;
        case 1:
            func_020d2040();
            M2C_FIELD(&data_0213b890, u8 *, 0x1F) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1F) - 1);
            if (M2C_FIELD(&data_0213b890, u8 *, 0x1F) == 0) {
                M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
                M2C_FIELD(&data_0213b890, u8 *, 0x22) = 0U;
            }
            return;
    }
}
