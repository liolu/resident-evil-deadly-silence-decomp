/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201b224(void *);                      /* extern */
M2C_UNK func_0201cc8c(void *);                      /* extern */
M2C_UNK func_0201cd60(void *);                      /* extern */
s32 func_0201d45c(M2C_UNK, s32);                    /* extern */
s16 func_0201df30(s32, s32);                        /* extern */
extern M2C_UNK data_02143cc0;

void func_0201d4c4(void *arg0) {
    if (!(M2C_FIELD(arg0, u8 *, 0x18A) & 4) && !(M2C_FIELD(arg0, s8 *, 0x188) & 0x80) && !(M2C_FIELD(arg0, u8 *, 0xC0) & 8) &&
        (func_0201d45c(0x2BC, 0x3B6) != 0)) {
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
    func_0201cd60(arg0);
}
