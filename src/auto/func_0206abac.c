/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206a704();                            /* extern */
M2C_UNK func_0206a980();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_0213be00;

void func_0206abac(void) {
    func_02056fb0(1);
    func_020b3a24(&data_0213bde0, 0xAA);
    if (func_020b39e4(&data_0213be00, 0x7F) != 0) {
        func_0206a980();
        return;
    }
    func_0206a704();
}
