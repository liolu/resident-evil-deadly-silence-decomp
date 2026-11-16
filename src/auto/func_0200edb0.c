/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ff881c(M2C_UNK *, void *);               /* extern */
M2C_UNK func_0200ed58();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02144c34;
extern M2C_UNK data_0214bcc0;

s32 func_0200edb0(void) {
    u8 temp_r5;
    u8 *var_r6;

    temp_r5 = M2C_FIELD(&data_0213ad98, u8 *, 2);
    var_r6  = (u8 *) M2C_FIELD(&data_0214bcc0, s32 *, 0x7B0) + 0x14;
    while (M2C_FIELD(var_r6, u16 *, 2) == temp_r5) {
        if (func_01ff881c(&data_02144c34, var_r6) != 0) {
            M2C_FIELD(&data_0213ad98, u8 *, 2) = (u8) M2C_FIELD(var_r6, u16 *, 0);
            func_0200ed58();
            return 1;
        }
        var_r6 += 0x14;
    }
    return 0;
}
