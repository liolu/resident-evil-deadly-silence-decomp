/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208e89c();                            /* extern */
M2C_UNK func_0208e8c4(M2C_UNK);                     /* extern */
extern u16 data_0213ad84;
extern M2C_UNK data_0213b890;
extern M2C_UNK func_0208dafc;

void func_0208e3dc(void) {
    if (data_0213ad84 == 0) {
        switch (M2C_FIELD(&data_0213b890, u8 *, 0x50)) { /* irregular */
            case 0:
                func_0208e8c4(1);
                func_0208e89c();
                return;
            case 1:
                M2C_FIELD(&data_0213b890, M2C_UNK **, 0x74) = &func_0208dafc;
                M2C_FIELD(&data_0213b890, s8 *, 0x54)       = 0;
                M2C_FIELD(&data_0213b890, s32 *, 0x78)      = 0;
                return;
            default:
                func_0208e8c4(0);
                func_0208e89c();
                break;
        }
    }
}
