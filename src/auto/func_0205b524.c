/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0205b25c();                            /* extern */
M2C_UNK func_0205b478();                            /* extern */
M2C_UNK func_020b6530(M2C_UNK);                     /* extern */
M2C_UNK func_020b67e8();                            /* extern */
extern M2C_UNK data_0213ad98;

void func_0205b524(void) {
    func_02056fb0(0x1B);
    func_02056fb0(0x1D);
    func_020b6530(0);
    func_020b67e8();
    if ((u32) M2C_FIELD(&data_0213ad98, u8 *, 7) < 8U) {
        func_0205b478();
        return;
    }
    func_0205b25c();
}
