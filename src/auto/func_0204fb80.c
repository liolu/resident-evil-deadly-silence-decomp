/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0204f154();                            /* extern */
M2C_UNK func_02050404(void *);                      /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02143cc0;

void func_0204fb80(void *arg0) {
    func_0204f154();
    func_02050404(arg0);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x17C) >= 0x2134) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 1;
    }
    func_02075738(1, 0x80);
    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFD6) == 0x14) {
        func_02075738(1, 0x80);
    }
}
