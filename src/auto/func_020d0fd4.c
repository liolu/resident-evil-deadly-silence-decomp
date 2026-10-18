/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_021263bc;
extern M2C_UNK data_021263bd;
extern M2C_UNK data_0213b890;

void func_020d0fd4(void) {
    s32 var_ip;
    u16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF2);
    if ((u32) temp_r0 >= 0x46U) {
        var_ip = 0;
    } else if ((u32) temp_r0 >= 0x1BU) {
        var_ip = 1;
    } else if ((u32) temp_r0 >= 0xFU) {
        var_ip = 2;
    } else if ((u32) temp_r0 >= 1U) {
        var_ip = 3;
    } else {
        var_ip = 4;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF8) = (u8) * ((u8 *) ((s8 *) &data_021263bc + (var_ip * 2)));
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xF9) = (u8) * ((u8 *) ((s8 *) &data_021263bd + (var_ip * 2)));
}
