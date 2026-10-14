/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8720(M2C_UNK, M2C_UNK *);          /* extern */
extern M2C_UNK data_021311e4;

s32 func_020e8024(void *arg0) {
    if (arg0 != NULL) {
        return M2C_FIELD(arg0, s32 *, 0x14);
    }
    func_020e8720(0, &data_021311e4);
    return 0;
}
