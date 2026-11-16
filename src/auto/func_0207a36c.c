/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02074f38();
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02147cc0;

void func_0207a36c(void) {
    u32 var_r2;
    u8 *ip;
    u8 r1;

    ip     = *(u8 **) ((u8 *) &data_02147cc0 + 0x538);
    r1     = M2C_FIELD(&data_0213ad98, u8 *, 6);
    var_r2 = 0;
    goto check;
body:
    var_r2 = (u8) (var_r2 + 1);
check:
    if (r1 != ip[var_r2 * 2]) {
        goto body;
    }
    M2C_FIELD(&data_0213ad98, u8 *, 0x12) = M2C_FIELD(&data_0213b890, u8 *, 9);
    ip[var_r2 * 2]                        = 0;
    func_02074f38();
}
