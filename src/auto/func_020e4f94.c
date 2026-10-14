/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_021094a0();                         /* extern */
M2C_UNK func_0211035c();      /* extern */

void func_020e4f94(s8 *arg0) {
    if (arg0 == NULL) {
        return;
    }
    func_021094a0(arg0 + 4);
    *arg0 = 0;
    func_0211035c(arg0, 0, 0x7C);
}
