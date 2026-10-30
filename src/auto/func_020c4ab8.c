/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200e998(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_02125798;
extern M2C_UNK data_02125799;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8b6;

void func_020c4ab8(void) {
    u8 temp_r1;
    u8 temp_r4;

    M2C_FIELD(&data_0213b890, u8 *, 0x24) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x24) - 1);
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 0) {
        temp_r4                               = M2C_FIELD(&data_0213b890, u8 *, 0x25);
        temp_r1                               = *((u8 *) ((s8 *) &data_02125798 + (temp_r4 * 2)));
        M2C_FIELD(&data_0213b890, u8 *, 0x25) = (u8) (temp_r4 + 1);
        func_0200e998(&data_0213b8b6, temp_r1);
        M2C_FIELD(&data_0213b890, u8 *, 0x24) = (u8) * ((u8 *) ((s8 *) &data_02125799 + (temp_r4 * 2)));
        if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 0) {
            M2C_FIELD(&data_0213b890, s8 *, 0x21) = 2;
        }
    }
}
