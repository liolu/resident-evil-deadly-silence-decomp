/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206f13c();                            /* extern */
M2C_UNK func_0206f1c0();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213be00;

void func_0206f244(void) {
    func_02056fb0(0);
    if (func_020b39e4(&data_0213be00, 0x65) != 0) {
        func_0206f1c0();
        return;
    }
    func_0206f13c();
}
