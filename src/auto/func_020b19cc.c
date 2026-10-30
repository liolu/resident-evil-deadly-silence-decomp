/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c440c();                            /* extern */
M2C_UNK func_020c46d4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020c47b8();                            /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK func_02072550;
extern M2C_UNK func_020ae394;
extern M2C_UNK func_020d69c0;

void func_020b19cc(void) {
    if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) == 0) {
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) = 1U;
        func_020c47b8();
        func_020c46d4(0x18, 0);
    }
    func_020c440c();
    if (M2C_FIELD(&data_0213b890, u8 *, 1) == 5) {
        if (M2C_FIELD(&data_0213ad48, u8 *, 0) != 0) {
            if (M2C_FIELD(&data_0213ad48, u8 *, 1) & 1) {
                M2C_FIELD(&data_0213b2b4, M2C_UNK **, 0xA8) = &func_02072550;
                return;
            }
            M2C_FIELD(&data_0213ad48, u8 *, 1)          = 4U;
            M2C_FIELD(&data_0213b2b4, M2C_UNK **, 0xA8) = &func_020ae394;
            return;
        }
        M2C_FIELD(&data_0213b2b4, M2C_UNK **, 0xA8) = &func_020d69c0;
    }
}
