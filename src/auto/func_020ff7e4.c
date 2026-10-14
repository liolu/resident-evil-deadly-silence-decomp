/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02100220(u16);                         /* extern */
extern u16 data_021587dc;

u16 func_020ff7e4(u16 *arg0) {
    u16 temp_r4;

    temp_r4 = *arg0;
    *arg0 = 0;
    data_021587dc |= temp_r4;
    func_02100220(temp_r4);
    return temp_r4;
}
