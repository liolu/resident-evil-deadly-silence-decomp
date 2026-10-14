/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02110374(s8 *, s8 *, s32);             /* extern */
s32 func_0211282c(s8 *);                            /* extern */
extern s8 data_02152cb8;

void func_020e5870(s8 *arg0) {
    s32 temp_r2;

    temp_r2 = func_0211282c(&data_02152cb8);
    if (data_02152cb8 == 0) {
        *arg0 = 0;
        return;
    }
    func_02110374(arg0, &data_02152cb8, temp_r2 + 1);
}
