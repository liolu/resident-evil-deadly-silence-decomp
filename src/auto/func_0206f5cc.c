/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206f4c4();                            /* extern */
M2C_UNK func_0206f548();                            /* extern */
M2C_UNK func_02092bac();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213bde0;

void func_0206f5cc(void) {
    func_02056fb0(3);
    func_02092bac();
    if (func_020b39e4(&data_0213bde0, 0x6D) != 0) {
        func_0206f4c4();
        return;
    }
    func_0206f548();
}
