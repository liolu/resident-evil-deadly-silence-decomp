/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02091d4c(s32, M2C_UNK *, M2C_UNK, s32); /* extern */
M2C_UNK func_020bf8b8(M2C_UNK);                     /* extern */
extern M2C_UNK data_02125c10;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213f768;

void func_020c9e9c(void) {
    func_020bf8b8(0);
    func_02091d4c(*((u16 *) ((s8 *) &data_02125c10 + (M2C_FIELD(&data_0213b890, u8 *, 0x24) * 8))) | 0x7C00, &data_0213f768,
                  0x40, 0x01001100);
}
