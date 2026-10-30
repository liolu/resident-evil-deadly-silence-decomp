/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020cffb0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020d02ec(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_0213b890;

void func_020d00fc(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(arg0, u8 *, 3);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, u8 *, 3)  = 1U;
            M2C_FIELD(arg0, u16 *, 6) = 0x32U;
            func_020cffb0(arg0, 3);
            return;
        case 1:
            if (M2C_FIELD(&data_0213b890, u8 *, 0x1D) != 1) {
                M2C_FIELD(arg0, u16 *, 6) = (u16) (M2C_FIELD(arg0, u16 *, 6) - 1);
                if (M2C_FIELD(arg0, u16 *, 6) == 0) {
                    M2C_FIELD(arg0, s8 *, 0)              = 0;
                    M2C_FIELD(&data_0213b890, u8 *, 0x1F) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1F) - 1);
                    func_020d02ec(arg0, 4);
                }
            }
            return;
    }
}
