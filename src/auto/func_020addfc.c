/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020a0100(M2C_UNK);                         /* extern */
M2C_UNK func_020a04c8(M2C_UNK *, u8);               /* extern */
s32 func_020ad87c();                                /* extern */
M2C_UNK func_020add78(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_02121ebc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02144d90;

void func_020addfc(void) {
    M2C_UNK var_r4;

    if ((M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) == 3) && (func_020ad87c() == 2)) {
        func_020a04c8(&data_02144d90, 0x8EU);
        var_r4 = 1;
    } else {
        func_020a04c8(&data_02144d90, ((s8 *) &data_02121ebc)[M2C_FIELD(&data_02143cc0, u8 *, 0xF4D)]);
        var_r4 = 0;
    }
    M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xD0), s32 *, 0x14) = func_020a0100(1);
    func_020add78(M2C_FIELD(&data_02144cc0, void **, 0xD0), var_r4);
}
