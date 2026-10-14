/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020fec68(void *, void *);              /* extern */
M2C_UNK func_021061d8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0210626c(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_02125590;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba64;
extern M2C_UNK data_0213baa8;
extern M2C_UNK data_0213bae8;

void func_020c3b24(void) {
    u8 var_r5;
    void *temp_r0;

    func_021061d8(&data_0213bae8, 0, 0x20);
    M2C_FIELD(&data_0213b890, s32 *, 0x274) = 0x3800;
    func_0210626c(&data_02125590, &data_0213ba64, 0x84);
    var_r5 = 0;
    do {
        temp_r0 = (M2C_UNK *)((s8 *)&data_0213baa8 + (var_r5 * 0x10));
        func_020fec68(temp_r0, temp_r0);
        var_r5 += 1;
    } while ((u32) var_r5 < 4U);
}
