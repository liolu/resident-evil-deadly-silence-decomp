/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02074d78(M2C_UNK, u8, u8);             /* extern */
M2C_UNK func_02074f38();                            /* extern */
M2C_UNK func_02095468(u8);                          /* extern */
M2C_UNK func_020b37ac(void *);                      /* extern */
M2C_UNK func_020b502c();                            /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02144cc0;

void func_02074e88(void) {
    void *temp_r4;

    temp_r4 = M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xDC), void **, 8);
    func_020b502c();
    func_020b37ac(temp_r4);
    M2C_FIELD(&data_0213ad98, u8 *, 0x13) = (u8) M2C_FIELD(temp_r4, u8 *, 8);
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        func_02095468(M2C_FIELD(temp_r4, u8 *, 0x14));
    }
    func_02074d78(1, M2C_FIELD(temp_r4, u8 *, 8), M2C_FIELD(temp_r4, u8 *, 9));
    func_02074f38();
}
