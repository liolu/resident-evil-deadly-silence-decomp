/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b5698();                         /* extern */

u8 func_02059410(void *arg0) {
    u8 temp_r4;
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    temp_r4 = M2C_FIELD(temp_r1, u8 *, 1);
    func_020b5698(temp_r1 + 2);
    return temp_r4;
}
