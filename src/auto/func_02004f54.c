/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02004950();                                /* extern */
M2C_UNK func_02004d60();                            /* extern */
M2C_UNK func_0210c0bc(u16);                         /* extern */
M2C_UNK func_0210c0cc(u16);                         /* extern */
s32 func_0210c61c(s32);                             /* extern */
extern M2C_UNK data_02136eb0;
extern M2C_UNK data_02136fb0;

void func_02004f54(void) {
    func_0210c0cc(M2C_FIELD(&data_02136fb0, u16 *, 0xA6));
    if (func_0210c61c(0xD01) == 0) {
        M2C_FIELD(&data_02136eb0, s8 *, 0x1A5) = 1;
    }
    func_0210c0bc(M2C_FIELD(&data_02136fb0, u16 *, 0xA6));
    if (func_02004950() == 0) {
        func_02004d60();
    }
}
