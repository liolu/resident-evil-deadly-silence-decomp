/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020adad0();                            /* extern */
extern M2C_UNK data_02144c04;
extern M2C_UNK *data_027e000c;

void func_0205584c(s32 arg0) {
    M2C_UNK *temp_r4;

    temp_r4 = data_027e000c;
    data_027e000c = &data_02144c04;
    func_020adad0(arg0);
    data_027e000c = temp_r4;
}
