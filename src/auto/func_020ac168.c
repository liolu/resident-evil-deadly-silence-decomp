#include "m2c.h"

M2C_UNK func_020b81b8(u16, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK data_02121cbc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;

void func_020ac168(void) {
    func_020b81b8(*((u16 *) ((s8 *) &data_02121cbc + (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) * 2))), &data_02144c34, 0);
}
