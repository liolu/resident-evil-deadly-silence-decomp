/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020134fc(void *);                      /* extern */
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213ae60;

void func_020135cc(void) {
    s32 temp_r1;
    u8 var_r4;

    var_r4                             = 0;
    M2C_FIELD(&data_0213ae4c, s8 *, 2) = (s8) (M2C_FIELD(&data_0213ae4c, u16 *, 8) &
                                               (M2C_FIELD(&data_0213ae4c, u16 *, 8) ^ M2C_FIELD(&data_0213ae4c, u16 *, 0x10)));
    do {
        temp_r1 = var_r4 * 0xC;
        if (M2C_FIELD(((M2C_UNK *) ((s8 *) &data_0213ae4c + temp_r1)), s32 *, 0x1C) != 0) {
            func_020134fc((M2C_UNK *) ((s8 *) &data_0213ae60 + temp_r1));
        }
        var_r4 += 1;
    } while ((u32) var_r4 < 4U);
}
