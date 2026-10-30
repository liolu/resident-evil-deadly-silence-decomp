/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u16 func_020d7558();                                /* extern */
void *func_020d8e0c(M2C_UNK);                       /* extern */
extern M2C_UNK data_0213caa0;
extern M2C_UNK data_0213d1a0;

u16 func_020d889c(void) {
    void *temp_r0;

    if (M2C_FIELD(&data_0213caa0, u8 *, 0x706) == 0) {
        return func_020d7558();
    }
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x704) == 0) {
        temp_r0 = func_020d8e0c(0);
        if (temp_r0 != NULL) {
            return M2C_FIELD(temp_r0, u16 *, 2);
        }
    }
    return M2C_FIELD(&data_0213d1a0, u16 *, 0x18);
}
