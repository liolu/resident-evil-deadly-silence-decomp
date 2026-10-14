/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e6dc0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02130dcc;

void func_020e66cc(void *arg0, s8 arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8 *, 3) = arg1;
        return;
    }
    func_020e6dc0(&data_02130dcc);
}
