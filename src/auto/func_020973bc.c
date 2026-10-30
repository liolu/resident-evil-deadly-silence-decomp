/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02098030();                            /* extern */
extern void *data_02137ed8;
extern u16 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020973bc(void) {
    if (data_0213ad84 == 0) {
        M2C_FIELD(&data_0213b890, s32 *, 0x44) = 0;
        M2C_FIELD(data_02137ed8, u8 *, 0x24AF) = (u8) (M2C_FIELD(data_02137ed8, u8 *, 0x24AF) & ~4);
        func_02098030();
        M2C_FIELD(data_02137ed8, s8 *, 0) = 3;
    }
}
