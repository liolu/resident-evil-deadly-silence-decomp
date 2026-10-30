/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02070ecc(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad50;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bf46;

void func_020a49d8(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2);
    if (temp_r0 != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2) = (u8) (temp_r0 - 1);
        return;
    }
    func_02070ecc(&data_0213ad50, &data_0213bf46);
    func_020c46b4(0);
}
