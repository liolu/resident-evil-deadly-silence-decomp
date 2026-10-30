/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02091014(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
extern M2C_UNK data_02143cc0;

void func_0204f2dc(void) {
    func_02091014(0, 0x80, 5);
    if ((u32) M2C_FIELD(&data_02143cc0, u8 *, 0xFE6) > 0x18U) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xFE6)                              = 0xAU;
        *M2C_FIELD(M2C_FIELD(&data_02143cc0, void **, 0xF44), s32 **, 0x10) = M2C_FIELD(&data_02143cc0, u8 *, 0xFE6) << 0xC;
    }
}
