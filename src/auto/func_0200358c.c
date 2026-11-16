/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_021046d4(s32, s32);                       /* extern */
extern M2C_UNK data_0211afc8;

void func_0200358c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r2;
    void (**tbl)(s32, s32, s32);

    func_021046d4(arg1, arg3);
    if (arg0 >= 4) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    tbl = (void (**)(s32, s32, s32)) &data_0211afc8;
    tbl[var_r2](arg1, arg2, arg3);
}
