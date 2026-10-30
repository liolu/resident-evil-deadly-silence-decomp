/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02074e88();                            /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_0213be00;
extern M2C_UNK data_02144cc0;

void func_0207a4e0(void) {
    if (M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xDC), void **, 8), u8 *, 8) == 0x4D) {
        func_020b3a24(&data_0213be00, 0x7F);
        return;
    }
    func_02074e88();
}
