/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020d23f0(s32 arg0) {
    s32 temp_r2;
    s32 var_r1;
    s32 var_r1_2;

    if (arg0 < 0) {
        var_r1 = -0x01999800;
    } else if (arg0 == 0) {
        var_r1 = -0xDA7333;
    } else {
        temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD4);
        if (temp_r2 < 0x888800) {
            var_r1_2 = 0x15D851;
        } else {
            var_r1_2 = 0xAEC28;
        }
        var_r1 = temp_r2 + var_r1_2;
    }
    if (var_r1 > arg0) {
        var_r1 = arg0;
    }
    if (var_r1 > 0x06666000) {
        var_r1 = 0x06666000;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0xD4) = var_r1;
}
