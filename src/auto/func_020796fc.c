/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02079174();                            /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_0213be84;

void func_020796fc(s32 arg0) {
    func_020b3a24(&data_0213be84, arg0);
    if (arg0 == 4) {
        func_020b3a24(&data_0213be84, 0x16);
    }
    func_02079174();
}
