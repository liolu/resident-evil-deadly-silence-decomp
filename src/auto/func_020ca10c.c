/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
s32 func_020bf060(M2C_UNK, M2C_UNK);                /* extern */
s32 func_020bf0a0(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020c9ccc(M2C_UNK);                     /* extern */
M2C_UNK func_020c9e9c();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020ca10c(void) {
    u8 temp_r0;

    switch (M2C_FIELD(&data_0213b890, u8 *, 0x22)) { /* switch 1; irregular */
        case 0:                                         /* switch 1 */
            if (M2C_FIELD(&data_0213b890, u8 *, 0x25) != 0) {
                M2C_FIELD(&data_0213b890, u8 *, 0x25) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x25) - 1);
                return;
            }
            func_020b82fc(0x7D);
            M2C_FIELD(&data_0213b890, u8 *, 0x22) = 1U;
            return;
        case 1:                                         /* switch 1 */
            temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 2);
            switch (temp_r0) {                          /* switch 2; irregular */
                case 1:                                     /* switch 2 */
                    if (func_020bf0a0(0, 0x14) == 1) {
                        func_020c9e9c();
                        func_020c9ccc(2);
                        return;
                    }
                    return;
                case 0:                                     /* switch 2 */
                    if (func_020bf060(0, 0x14) == 1) {
                        func_020c9e9c();
                        func_020c9ccc(2);
                    }
                    break;
            }
            break;
    }
}
