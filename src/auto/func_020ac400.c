/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02059b28(void **);                         /* extern */
M2C_UNK func_020ac39c(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020adad0(M2C_UNK);                     /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;
extern void **data_027e000c;

void func_020ac400(void) {
    M2C_UNK var_r0;
    s32 temp_r0;
    void *temp_ip;

    if (M2C_FIELD(&data_02144cc0, s16 *, 0xA) != 0) {
        temp_r0 = func_02059b28(data_027e000c);
        if (temp_r0 != 2) {
            if (temp_r0 == 0) {
                var_r0 = 0x95;
            } else {
                var_r0 = 0x7F;
            }
            func_020adad0(var_r0);
            temp_ip                                = M2C_FIELD(*data_027e000c, void **, 0x10);
            M2C_FIELD(temp_ip, s32 *, 0)           = (s32) (M2C_FIELD(M2C_FIELD(temp_ip, void **, 8), u16 *, 4) << 0xC);
            M2C_FIELD(&data_02143cc0, s8 *, 0xFDC) = 0;
            func_020ac39c(0, 0x1000);
        }
    }
}
