/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
void func_02115f28(double, double);
s32 func_02116344();                                /* extern */
double func_021164b0(s32);
extern u8 data_0211bc31[];
extern void *data_0213ad2c;

void func_02012298(void *arg0, void *arg1) {

    u8 temp_r2;

    temp_r2                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        M2C_FIELD(arg0, s8 *, 5)    = 1;
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x32U;
        func_020b8310(data_0211bc31[M2C_FIELD(data_0213ad2c, u8 *, 9) * 3]);
        M2C_FIELD(arg1, s8 *, 0xEB) = 1;
    }
    func_02115f28(func_021164b0(M2C_FIELD(arg1, s32 *, 0)), 6553.6);
    M2C_FIELD(arg1, s32 *, 0) = func_02116344();
}
