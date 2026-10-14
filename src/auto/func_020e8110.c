/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8720(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK data_0213122c;

s8 func_020e8110(void *arg0) {
    if (arg0 != NULL) {
        return M2C_FIELD(arg0, s8 *, 1);
    }
    func_020e8720(0, &data_0213122c);
    return 0;
}
