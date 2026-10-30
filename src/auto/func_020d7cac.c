/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d7b28();                                /* extern */
s32 func_020d7c40();                                /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02126ec8;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *);
extern M2C_UNK data_02142cc0;
extern M2C_UNK data_021431c0;

void func_020d7cac(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        return;
    }
    func_020d880c(1);
    if (M2C_FIELD(&data_021431c0, u16 *, 0xA6) != 0) {
        if (M2C_FIELD(&data_02142cc0, s32 *, 0x5B0) != 0) {
            if (func_020d7c40() == 0) {
                func_020d880c(9);
            }
        } else if (func_020d7b28() == 0) {
            if (data_0213ad20 != NULL) {
                data_0213ad20(&data_02126ec8);
            }
            func_020d880c(9);
        }
    }
}
