/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e724(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
extern M2C_UNK data_02141d40;
extern M2C_UNK func_020d7054;

s32 func_020d70b0(void) {
    func_020d880c(3);
    if (func_0210e724(&data_02141d40, &func_020d7054, 1) == 2) {
        return 1;
    }
    func_020d87f0();
    func_020d880c(0xA);
    return 0;
}
