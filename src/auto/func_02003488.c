/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffc510(M2C_UNK *);                   /* extern */
M2C_UNK func_020b8728(M2C_UNK *);                   /* extern */
M2C_UNK func_020f7d04();                            /* extern */
extern M2C_UNK data_02144b40;

void func_02003488(void) {
    func_020f7d04();
    func_020b8728(&data_02144b40);
    func_01ffc510(&data_02144b40);
}
