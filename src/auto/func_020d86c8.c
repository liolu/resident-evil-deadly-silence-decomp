/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210f978(M2C_UNK *, s32, M2C_UNK *);       /* extern */
extern M2C_UNK data_02141cc0;
extern M2C_UNK data_02142cc0;
extern M2C_UNK data_02143280;
extern M2C_UNK func_020d8684;

s32 func_020d86c8(void) {
    func_020d880c(3);
    if (func_0210f978(&func_020d8684,
                      M2C_FIELD(&data_02142cc0, s32(**)(M2C_UNK *, M2C_UNK *), 0x5AC)(&data_02143280, &data_02141cc0),
                      &data_02143280) == 2) {
        return 1;
    }
    func_020d87f0();
    func_020d880c(9);
    return 0;
}
