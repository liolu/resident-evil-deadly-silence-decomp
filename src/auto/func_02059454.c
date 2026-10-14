/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020599dc(u8, u8);                      /* extern */

s32 func_02059454(void *arg0) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(arg0, void **, 8);
    func_020599dc(M2C_FIELD(temp_r1, u8 *, 1), M2C_FIELD(temp_r1, u8 *, 2));
    return 4;
}
