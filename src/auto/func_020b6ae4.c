/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020b82fc(u16);
extern u16 *data_02123648[];
extern u16 *data_02123698[];
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bb18;

void func_020b6ae4(void) {
    u16 var_r0;

    if (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) {
        var_r0 = data_02123698[M2C_FIELD(&data_0213ad98, u8 *, 0)][M2C_FIELD(&data_0213ad98, u8 *, 1)];
    } else {
        var_r0 = data_02123648[((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1C)) >> 0x1E]
                              [M2C_FIELD(&data_0213ad98, u8 *, 1)];
    }
    func_020b82fc(var_r0);
}
