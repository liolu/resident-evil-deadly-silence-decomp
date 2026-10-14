/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e4a28(M2C_UNK *);                   /* extern */
M2C_UNK func_021126e0(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK (*data_0214f1c4)(s32, M2C_UNK *);
extern s32 data_0214f1c8;
extern M2C_UNK data_0214f1ec;

void func_020deb88(M2C_UNK arg0) {
    func_021126e0(&data_0214f1ec, arg0, 0xFF);
    if (data_0214f1c4 != NULL) {
        data_0214f1c4(data_0214f1c8, &data_0214f1ec);
    }
    func_020e4a28(&data_0214f1ec);
}
