/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02006f90();                    /* extern */
s32 func_02118728();                    /* extern */
extern void *data_02137298;

s32 func_02006c20(s32 arg0) {
    M2C_UNK saved_reg_r5;
    s32 var_r0;
    s32 var_r5;
    u32 temp_r1;
    u32 temp_r3;
    void *temp_r4;

    var_r5  = saved_reg_r5;
    temp_r4 = data_02137298;
    temp_r3 = M2C_FIELD(temp_r4, u32 *, 0x3EF8);
    switch (temp_r3) {                              /* switch 1; irregular */
        case 0x105D:                                    /* switch 1 */
            var_r0 = func_02118728(arg0 * 0x1F40, 0x3E8);
            break;
        case 0xBDF:                                     /* switch 1 */
            var_r0 = func_02118728(arg0 * 0x2B11, 0x3E8);
            break;
        case 0x82E:                                     /* switch 1 */
            var_r0 = func_02118728(arg0 * 0x3E80, 0x3E8);
            break;
        case 0x5EF:                                     /* switch 1 */
            var_r0 = func_02118728(arg0 * 0x5622, 0x3E8);
            break;
        case 0x417:                                     /* switch 1 */
            var_r0 = func_02118728(arg0 * 0x7D00, 0x3E8);
            break;
        default:                                        /* switch 1 */
            var_r0 = func_02118728(temp_r3 * arg0, 0x3E8);
            break;
    }
    temp_r1 = M2C_FIELD(temp_r4, u32 *, 0x3EEC);
    switch (temp_r1) {                              /* switch 2 */
        default:                                        /* switch 2 */
            break;
        case 0:                                         /* switch 2 */
        case 2:                                         /* switch 2 */
            var_r5 = 1;
            break;
        case 1:                                         /* switch 2 */
        case 3:                                         /* switch 2 */
        case 4:                                         /* switch 2 */
        case 5:                                         /* switch 2 */
            var_r5 = 2;
            break;
    }
    if ((u32) (var_r0 * var_r5) > (u32) M2C_FIELD(temp_r4, u32 *, 0x3EF4)) {
        return -0xA;
    }
    func_02006f90(var_r0, var_r5);
    return 0;
}
