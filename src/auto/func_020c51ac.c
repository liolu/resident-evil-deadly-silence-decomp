/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4da4();           /* extern */
M2C_UNK func_020c4dd8();                         /* extern */
s32 func_020c83d8();                  /* extern */
extern M2C_UNK data_021258e0;
extern M2C_UNK data_021258ec;
extern M2C_UNK data_0213b890;

s32 func_020c51ac(void) {
    s32 var_r0;
    u8 temp_r1;

    func_020c4dd8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x128) = 0x503;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x140) = 0x1000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x142) = 0x1000;
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x4B);
    var_r0  = temp_r1 & 0x80;
    if (var_r0 != 0) {
        if ((u8) (temp_r1 & 0x7F) == 0) {
            func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, &data_021258e0);
        } else {
            func_020c4da4(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, &data_021258ec);
        }
        var_r0 =
            func_020c83d8(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x120, M2C_FIELD(&data_0213b890, void **, 0x4C) + 0x114);
    }
    return var_r0;
}
