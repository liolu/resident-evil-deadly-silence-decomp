/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
s32 func_02116344();                                /* extern */
double func_021164b0(s32);
void func_021169f8(double, double);
extern u8 data_0211bc31[];
extern void *data_0213ad2c;

void func_02012210(void *arg0, void *arg1) {

    u8 temp_r2;

    temp_r2                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        M2C_FIELD(arg0, s8 *, 5)    = 2;
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x1EU;
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x28) {
        func_020b8310(data_0211bc31[M2C_FIELD(data_0213ad2c, u8 *, 9) * 3]);
    }
    func_021169f8(func_021164b0(M2C_FIELD(arg1, s32 *, 8)), 368.64);

    M2C_FIELD(arg1, s32 *, 8) = func_02116344();
}
