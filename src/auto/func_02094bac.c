/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0209563c();                              /* extern */
extern M2C_UNK data_0213ad48;

s32 func_02094bac(s32 arg0) {
    u8 temp_r1;
    void *temp_r0;

    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        temp_r0 = func_0209563c(arg0);
        if (temp_r0 != NULL) {
            temp_r1 = M2C_FIELD(temp_r0, u8 *, 0x14);
            if ((((u32) (temp_r1 << 0x1F) >> 0x1F) == 0) && (((u32) (temp_r1 << 0x1E) >> 0x1F) == 0) &&
                (((u32) (temp_r1 << 0x18) >> 0x1F) != 0)) {
                return 1;
            }
        }
    }
    return 0;
}
