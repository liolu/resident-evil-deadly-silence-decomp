#include "m2c.h"

M2C_UNK func_020adad0(s32);
extern M2C_UNK data_02143cc0;

void func_020adc50(s32 arg0) {
    s32 var_r0;

    switch (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E)) {
        case 3:
        case 6:
        case 7:
        case 8:
        case 9:
            if (arg0 != 0) {
                var_r0 = 0x8016;
            } else {
                var_r0 = 0x8014;
            }
            break;
        case 10:
            if (arg0 != 0) {
                var_r0 = 0x8032;
            } else {
                var_r0 = 0x8031;
            }
            break;
        default:
        case 0:
        case 1:
        case 2:
        case 4:
        case 5:
            if (arg0 != 0) {
                var_r0 = 0x8005;
            } else {
                var_r0 = 0x8002;
            }
            break;
    }
    func_020adad0(var_r0);
}
