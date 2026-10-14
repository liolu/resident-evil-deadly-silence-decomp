/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e4a9c();                            /* extern */
M2C_UNK func_020e4aac();                            /* extern */
M2C_UNK func_020e543c(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK data_021308b0;

void func_020e4d80(void *arg0) {
    if (arg0 == NULL) {
        func_020e543c(0, &data_021308b0);
        return;
    }
    func_020e4aac();
    M2C_FIELD(arg0, s8 *, 1) = 0;
    func_020e4a9c();
}
