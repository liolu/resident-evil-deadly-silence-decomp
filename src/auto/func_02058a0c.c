/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s16 func_02070f28(u8);                              /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;

s32 func_02058a0c(void *arg0) {
    s16 var_r0;
    u8 temp_r1;
    void *temp_r0;

    temp_r0 = M2C_FIELD(arg0, void **, 8);
    temp_r1 = M2C_FIELD(temp_r0, u8 *, 1);
    var_r0 = M2C_FIELD(temp_r0, s16 *, 2);
    switch (temp_r1) {
    default:
        break;
    case 0:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x30) = (s32) var_r0;
        break;
    case 1:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x34) = (s32) var_r0;
        break;
    case 2:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s32 *, 0x38) = (s32) var_r0;
        break;
    case 3:
        if ((s32) var_r0 >= 0) {
            var_r0 = func_02070f28(M2C_FIELD(&data_02143cc0, u8 *, 0xF4D));
        } else if (var_r0 == -2) {
            M2C_FIELD(&data_02143cc0, s8 *, 0xF43) = 1;
            M2C_FIELD(&data_02144cc0, u8 *, 0xE3) = (u8) (M2C_FIELD(&data_02144cc0, u8 *, 0xE3) | 1);
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0x94) = var_r0;
        break;
    case 4:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0xAA) = var_r0;
        break;
    case 5:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), s16 *, 0xAC) = var_r0;
        break;
    }
    return 4;
}
