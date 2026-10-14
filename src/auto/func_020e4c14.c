/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e543c(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK data_02130834;

s32 func_020e4c14(void *arg0) {
    if (arg0 != NULL) {
        return M2C_FIELD(arg0, s32 *, 0x5C);
    }
    func_020e543c(0, &data_02130834);
    return 0;
}
