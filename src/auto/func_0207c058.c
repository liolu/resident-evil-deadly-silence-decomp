/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02090fc4(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_0207c058(void *arg0) {
    u8 temp_r1;
    void *temp_r2;

    func_02090fc4(0, 0x1000, 0);
    temp_r2 = M2C_FIELD(arg0, void **, 0);
    temp_r1 = M2C_FIELD(temp_r2, u8 *, 0x91);
    switch (temp_r1) {                              /* irregular */
        case 0:
            if ((u32) M2C_FIELD(temp_r2, u8 *, 0xA2) >= 0xAU) {
                M2C_FIELD(temp_r2, u8 *, 0x91) = (u8) (temp_r1 + 1);
                case 1:
                    M2C_FIELD(arg0, u8 *, 0x17) = (u8) (M2C_FIELD(arg0, u8 *, 0x17) - 8);
                    if ((u32) M2C_FIELD(arg0, u8 *, 0x17) > 0x1FU) {
                        M2C_FIELD(arg0, u8 *, 0x17) = 0U;
                    }
                    if (M2C_FIELD(arg0, u8 *, 0x17) == 0) {
                        M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0xB)  = 0;
                        M2C_FIELD(M2C_FIELD(arg0, void **, 0), s8 *, 0x90) = 2;
                    }
            }
            return;
    }
}
