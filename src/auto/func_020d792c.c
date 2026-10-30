/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
s32 func_0210e9a0(M2C_UNK *, M2C_UNK *, u16, M2C_UNK *, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK data_02142c40;
extern M2C_UNK data_02142cc0;
extern M2C_UNK data_02142de0;
extern M2C_UNK func_020d77c8;

s32 func_020d792c(void) {
    if (func_0210e9a0(&func_020d77c8, &data_02142de0, (u16) M2C_FIELD(&data_02142cc0, s32 *, 0x4A4), &data_02142c40,
                      (s32) (u16) M2C_FIELD(&data_02142cc0, s32 *, 0x4A0), 1, 0, 0, 0, 0, 0) == 2) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
