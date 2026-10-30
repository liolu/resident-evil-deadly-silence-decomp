/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02094c68();                            /* extern */
M2C_UNK func_0209f034(u8);                          /* extern */
u32 func_0209f0bc();                                /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b3a00(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020b6a6c();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_0213be20;

void func_0209f0e8(void) {
    s32 var_r5;
    u32 temp_r0;
    u32 temp_r0_2;
    u32 var_r4;

    if (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1C) >> 0x1E) != 1) {
        func_020b3a00(&data_0213be20, 0x3F);
        return;
    }
    if (M2C_FIELD(&data_0213ad98, u8 *, 1) != 8) {
        func_020b3a00(&data_0213be20, 0x3F);
        func_020b3a00(&data_0213bde0, 0x20);
        return;
    }
    if (func_020b39e4(&data_0213bde0, 0x29) != 0) {
        func_020b3a00(&data_0213be20, 0x3F);
        func_0209f034(0U);
        return;
    }
    if (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 0) {
        var_r4 = 5;
    } else {
        var_r4 = 9;
    }
    if (func_020b39e4(&data_0213bde0, 0x20) == 0) {
        func_020b3a00(&data_0213bde0, 0x21);
        func_020b3a00(&data_0213bde0, 0x22);
        func_020b3a00(&data_0213bde0, 0x23);
        func_020b3a00(&data_0213bde0, 0x24);
        func_020b3a00(&data_0213bde0, 0x25);
        func_020b3a00(&data_0213bde0, 0x26);
        func_020b3a00(&data_0213bde0, 0x27);
        func_020b3a00(&data_0213bde0, 0x28);
        temp_r0 = func_0209f0bc();
        switch (temp_r0) {                          /* switch 1 */
            default:                                    /* switch 1 */
                break;
            case 0:                                     /* switch 1 */
                func_020b3a24(&data_0213bde0, 0x25);
                break;
            case 1:                                     /* switch 1 */
                func_020b3a24(&data_0213bde0, 0x26);
                break;
            case 2:                                     /* switch 1 */
                func_020b3a24(&data_0213bde0, 0x28);
                break;
            case 3:                                     /* switch 1 */
                func_020b3a24(&data_0213bde0, 0x27);
                break;
        }
        func_020b3a24(&data_0213bde0, 0x20);
    }
    var_r5    = 0;
    temp_r0_2 = func_0209f0bc();
    switch (temp_r0_2) {                            /* switch 2 */
        default:                                        /* switch 2 */
            break;
        case 0:                                         /* switch 2 */
            func_020b3a24(&data_0213bde0, 0x21);
            if (func_020b39e4(&data_0213bde0, 0x25) != 0) {
                var_r5 = 1;
            }
            break;
        case 1:                                         /* switch 2 */
            func_020b3a24(&data_0213bde0, 0x22);
            if (func_020b39e4(&data_0213bde0, 0x26) != 0) {
                var_r5 = 1;
            }
            break;
        case 2:                                         /* switch 2 */
            func_020b3a24(&data_0213bde0, 0x24);
            if (func_020b39e4(&data_0213bde0, 0x28) != 0) {
                var_r5 = 1;
            }
            break;
        case 3:                                         /* switch 2 */
            func_020b3a24(&data_0213bde0, 0x23);
            if (func_020b39e4(&data_0213bde0, 0x27) != 0) {
                var_r5 = 1;
            }
            break;
    }
    if ((var_r5 != 0) && (func_020b39e4(&data_0213bde0, 0x21) != 0) && (func_020b39e4(&data_0213bde0, 0x22) != 0) &&
        (func_020b39e4(&data_0213bde0, 0x23) != 0) && (func_020b39e4(&data_0213bde0, 0x24) != 0)) {
        func_02094c68();
        func_020b3a00(&data_0213bde0, 0x20);
    }
    func_0209f034((u8) (var_r4 - M2C_FIELD(&data_0213bb18, u8 *, 0x203)));
    if ((u32) M2C_FIELD(&data_0213bb18, u8 *, 0x203) >= var_r4) {
        func_020b3a24(&data_0213bde0, 0x29);
        func_020b6a6c();
    }
}
