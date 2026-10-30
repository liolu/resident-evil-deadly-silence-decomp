/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d8618();                                /* extern */
s32 func_020d86c8();                                /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02142cc0;

void func_020d8734(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d880c(9);
        return;
    }
    if (M2C_FIELD(&data_02142cc0, s32 *, 0x5AC) != 0) {
        if (func_020d86c8() == 0) {
            func_020d880c(9);
        }
    } else if (func_020d8618() == 0) {
        func_020d880c(9);
    }
}
