/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8720(M2C_UNK, M2C_UNK *);          /* extern */
M2C_UNK func_020e877c();                            /* extern */
M2C_UNK func_020e8788();                            /* extern */
extern M2C_UNK data_02131244;

void func_020e814c(void *arg0) {
    if (arg0 == NULL) {
        func_020e8720(0, &data_02131244);
        return;
    }
    func_020e8788();
    M2C_FIELD(arg0, s8 *, 1) = 0;
    func_020e877c();
}
