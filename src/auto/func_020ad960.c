/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ad928(M2C_UNK);                     /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02147cc0;

void func_020ad960(void) {
    if (((u32) M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) <= 1U) &&
        (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) != *M2C_FIELD(&data_02147cc0, u8 **, 0x53C))) {
        func_020ad928(1);
    }
}
