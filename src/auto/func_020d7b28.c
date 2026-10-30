/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e274(M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK, s32); /* extern */
extern M2C_UNK data_02126e6c;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *);
extern M2C_UNK data_0213d184;
extern M2C_UNK data_02141cc0;
extern M2C_UNK data_02142cc0;
extern M2C_UNK data_02143180;
extern M2C_UNK func_020d79b4;

s32 func_020d7b28(void) {
    u16 var_r0;

    if ((u32) (M2C_FIELD(&data_02141cc0, s32 *, 0x40) - 4) <= 2U) {
        if (data_0213ad20 != NULL) {
            data_0213ad20(&data_02126e6c);
        }
        return 1;
    }
    func_020d880c(3);
    if (M2C_FIELD(&data_02142cc0, s32 *, 0x5B0) != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (func_0210e274(&func_020d79b4, &data_02143180, &data_0213d184, 1, (s32) var_r0) == 2) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
