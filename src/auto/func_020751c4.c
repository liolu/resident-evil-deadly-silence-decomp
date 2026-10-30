/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207518c(void *);                      /* extern */
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213becc;
extern M2C_UNK data_0213bf2e;

void func_020751c4(void) {
    u32 var_r5;
    u32 var_r5_2;

    var_r5 = 0;
    do {
        func_0207518c((M2C_UNK *) ((s8 *) &data_0213becc + (var_r5 * 2)));
        var_r5 += 1;
    } while (var_r5 < 0x30U);
    var_r5_2                               = 0;
    M2C_FIELD(&data_0213bdcc, s8 *, 0x160) = 0;
    M2C_FIELD(&data_0213bdcc, s8 *, 0x161) = 0;
    do {
        func_0207518c((M2C_UNK *) ((s8 *) &data_0213bf2e + (var_r5_2 * 2)));
        var_r5_2 += 1;
    } while (var_r5_2 < 0xCU);
}
