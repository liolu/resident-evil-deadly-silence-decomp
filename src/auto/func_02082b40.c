/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020823b4(void **, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_02082b40(void **arg0) {
    void *temp_r1;

    func_020823b4(arg0, 0xF, 0, 0);
    temp_r1                        = *arg0;
    M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
}
