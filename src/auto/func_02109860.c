/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_021098bc();                            /* extern */
extern s32 data_0215a7b8;

void func_02109860(s32 arg0) {
    if (data_0215a7b8 != 0) {
        return;
    }
    data_0215a7b8 = 1;
    func_021098bc(arg0);
}
