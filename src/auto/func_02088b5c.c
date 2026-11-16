/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0211f77c;
extern M2C_UNK data_0211f7cc;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213e2a8;

void func_02088b5c(u32 arg0) {
    u8 *var_r3;
    u32 var_r1;

    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 1) {
        var_r3 = (u8 *) &data_0211f77c;
        var_r1 = 0xA;
    } else {
        var_r1 = 0x23;
        var_r3 = (u8 *) &data_0211f7cc;
    }
    if (var_r1 <= arg0) {
        M2C_FIELD(&data_0213e2a8, s16 *, 0x56) = 0;
        M2C_FIELD(&data_0213e2a8, s16 *, 0x54) = M2C_FIELD(&data_0213e2a8, s16 *, 0x56);
        return;
    }
    M2C_FIELD(&data_0213e2a8, s16 *, 0x54) = M2C_FIELD(var_r3, s16 *, arg0 * 8);
    M2C_FIELD(&data_0213e2a8, s16 *, 0x56) = M2C_FIELD(var_r3, s16 *, arg0 * 8 + 2);
}
