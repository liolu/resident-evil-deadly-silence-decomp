/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_0205568c(void *, u8);                    /* extern */
M2C_UNK func_020b2b28(u8);                          /* extern */
s32 func_020b3820(void *);                          /* extern */
extern void *data_0213daa8;
extern void *data_027e000c;

s32 func_020b2c04(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4 = data_0213daa8;
    data_0213daa8 = temp_r4 + 0x16;
    if ((M2C_FIELD(temp_r4, u8 *, 3) == 0xFF) || (func_020b3820(temp_r4) == 0)) {
        temp_r0 = func_0205568c(temp_r4, (u8) (M2C_FIELD(temp_r4, u8 *, 0x12) & 0xF));
        data_027e000c = temp_r0;
        func_020b2b28(M2C_FIELD(temp_r0, u8 *, 9));
    }
    return 1;
}
