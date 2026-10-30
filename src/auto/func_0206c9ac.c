/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206c9ec();                            /* extern */
M2C_UNK func_0206cc3c();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213be00;

void func_0206c9ac(void) {
    func_02056fb0(8);
    if (func_020b39e4(&data_0213be00, 0x65) != 0) {
        func_0206cc3c();
        return;
    }
    func_0206c9ec();
}
