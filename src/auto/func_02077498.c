/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02070088(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_02070110(M2C_UNK *, M2C_UNK *);            /* extern */
M2C_UNK func_02070438(s32);                         /* extern */
M2C_UNK func_02105528();                            /* extern */
M2C_UNK func_02106088(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK data_0211e6e8;
extern M2C_UNK data_0213afec;
extern M2C_UNK data_0213b014;

void func_02077498(void) {
    s32 temp_r0;

    if (func_02070110(&data_0213afec, &data_0211e6e8) == 0) {
        func_02105528();
        return;
    }
    temp_r0 = func_02070088(&data_0213afec, 1, 0, 1);
    if (temp_r0 == 0) {
        func_02105528();
        return;
    }
    func_02106088(temp_r0, &data_0213b014, 0x52);
    func_02070438(temp_r0);
}
