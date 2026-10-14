/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fe7c(); /* extern */
extern M2C_UNK data_0213ade4;
extern M2C_UNK data_0213b2b4;

void func_0209cac4(M2C_UNK arg0) {
    func_0206fe7c(&data_0213ade4, 2, arg0, 1, M2C_FIELD(&data_0213b2b4, void **, 0xB8) + 0x2848);
    M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) = (u8) (M2C_FIELD(M2C_FIELD(&data_0213b2b4, void **, 0xB8), u8 *, 0x2F61) | 0x10);
}
