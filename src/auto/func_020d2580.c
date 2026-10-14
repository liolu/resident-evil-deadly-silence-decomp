/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020d1f7c(M2C_UNK);                     /* extern */
M2C_UNK func_020d23f0(s32);                         /* extern */
s32 func_020d2468();                                /* extern */
s32 func_020fef58(s32, s32);                        /* extern */
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b890;

void func_020d2580(void) {
    s32 var_r4;

    func_020d1f7c(0);
    var_r4 = -1;
    if ((M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0) && (func_020d2468() == 1)) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 4) = (s32) (func_020fef58((0x9E - M2C_FIELD(&data_0213ae4c, u16 *, 4)) << 0xC, (0x56 - M2C_FIELD(&data_0213ae4c, u16 *, 6)) << 0xC) << 0x10);
        M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
        var_r4 = 0;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD0) = var_r4;
    func_020d23f0(var_r4);
}
