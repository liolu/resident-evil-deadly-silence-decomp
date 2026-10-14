/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020deb88(M2C_UNK *);                   /* extern */
M2C_UNK func_020e6700(s32);                         /* extern */
extern M2C_UNK data_0212fdd8;

void func_020df008(void *arg0) {
    if (arg0 == NULL) {
        func_020deb88(&data_0212fdd8);
        return;
    }
    func_020e6700(M2C_FIELD(arg0, s32 *, 0x94));
}
