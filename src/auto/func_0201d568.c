/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201b224(void *);                      /* extern */
M2C_UNK func_0201cc8c(void *);                      /* extern */
M2C_UNK func_0201cd34(void *);                      /* extern */
s32 func_0201d45c(M2C_UNK, M2C_UNK);                /* extern */
s16 func_0201df30(s32, s32);                        /* extern */
extern M2C_UNK data_02143cc0;

void func_0201d568(void *arg0) {
    if (func_0201d45c(0x200, 0x4B0) != 0) {
        M2C_FIELD(arg0, s16 *, 0x44) =
            func_0201df30(M2C_FIELD(&data_02143cc0, s32 *, 0xF74), M2C_FIELD(&data_02143cc0, s32 *, 0xF7C));
        M2C_FIELD(arg0, s8 *, 0x90) = 5;
        M2C_FIELD(arg0, u8 *, 0x91) = 0U;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
        func_0201b224(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x91) == 0) {
        func_0201cc8c(arg0);
    }
    func_0201cd34(arg0);
}
