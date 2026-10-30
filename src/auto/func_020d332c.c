/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d311c();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020d332c(void) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x50);
    if ((u32) temp_r0 < 0xC0U) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x50) = (u16) (temp_r0 + 8);
        return;
    }
    func_020d311c();
}
