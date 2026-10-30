/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020d1808(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 2) {
        if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0) {
            func_020c4798(3);
        }
    } else if (*M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x258), s32 **, 0x10) == 0x1E000) {
        func_020c4798(3);
    }
}
