/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206ce88();                            /* extern */
M2C_UNK func_0206d0f8();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213bde0;

void func_0206d368(void) {
    func_02056fb0(3);
    if (func_020b39e4(&data_0213bde0, 0x25) != 0) {
        func_0206ce88();
        return;
    }
    func_0206d0f8();
}
