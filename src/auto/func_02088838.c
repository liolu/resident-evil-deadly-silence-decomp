/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02094cb0(u8);                              /* extern */
M2C_UNK func_02094d0c(u8);                          /* extern */
void *func_020f3244(M2C_UNK *, s32);                /* extern */
M2C_UNK func_021061d8(void *, M2C_UNK, s32);        /* extern */
extern M2C_UNK data_021375ac;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b3ac;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02147cc0;

s32 func_02088838(void) {
    void *temp_r0;

    temp_r0 = func_020f3244(&data_0213b3ac, 0x2CDC);
    if (temp_r0 == NULL) {
        return 0;
    }
    func_021061d8(temp_r0, 0, 0x2CDC);
    M2C_FIELD(&data_021375ac, u8 *, 8)                                = 0U;
    M2C_FIELD(&data_021375ac, u8 *, 7)                                = (u8) M2C_FIELD(&data_021375ac, u8 *, 8);
    M2C_FIELD(&data_02147cc0, s8 *, 0x541)                            = 1;
    M2C_FIELD(&data_021375ac, void **, 0x64)                          = temp_r0;
    M2C_FIELD(&data_021375ac, u8 *, 6)                                = (u8) M2C_FIELD(&data_021375ac, u8 *, 7);
    M2C_FIELD(&data_021375ac, s8 *, 0)                                = 1;
    M2C_FIELD(&data_021375ac, s8 *, 4)                                = 1;
    M2C_FIELD(&data_021375ac, s8 *, 2)                                = 0;
    M2C_FIELD(&data_021375ac, s8 *, 0xE)                              = 0;
    M2C_FIELD(&data_021375ac, u8 *, 5)                                = (u8) M2C_FIELD(&data_021375ac, u8 *, 6);
    M2C_FIELD(&data_021375ac, s8 *, 0xC)                              = 0;
    M2C_FIELD(&data_021375ac, s8 *, 0x11)                             = 0;
    M2C_FIELD(&data_021375ac, s32 *, 0x18)                            = 0;
    M2C_FIELD(&data_021375ac, s8 *, 0x12)                             = 0;
    M2C_FIELD(temp_r0, s32 *, 0x59C)                                  = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s32 *, 0x5A0) = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s32 *, 0x5A4) = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s32 *, 0x5A8) = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s8 *, 0x5AC)  = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s8 *, 0x5AE)  = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s8 *, 0x5AD)  = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s8 *, 0x5AF)  = 0;
    M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), s8 *, 0x5B0)  = 0;
    M2C_FIELD(&data_021375ac, u16 *, 0x4C)                            = (u16) M2C_FIELD(&data_02143cc0, u8 *, 0xF4D);
    M2C_FIELD(&data_021375ac, s16 *, 0x4E)                            = (s16) M2C_FIELD(&data_02144bc0, s16 *, 0xD8);
    M2C_FIELD(&data_021375ac, s32 *, 0x50)                            = 0;
    M2C_FIELD(&data_021375ac, s32 *, 0x54)                            = 0;
    M2C_FIELD(&data_021375ac, s32 *, 0x5C)                            = 0;
    M2C_FIELD(&data_021375ac, s8 *, 0x62)                             = 0;
    M2C_FIELD(&data_021375ac, s16 *, 0x60)                            = 0;
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 1) {
        M2C_FIELD(&data_021375ac, s32 *, 0x58) = 0;
    } else {
        M2C_FIELD(&data_021375ac, s32 *, 0x58) = func_02094cb0(M2C_FIELD(&data_021375ac, u8 *, 0x21));
        func_02094d0c(M2C_FIELD(&data_021375ac, u8 *, 0x21));
    }
    if ((u32) M2C_FIELD(&data_021375ac, u16 *, 0x4C) >= 9U) {
        M2C_FIELD(&data_021375ac, u16 *, 0x4C) = 0U;
    }
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x10000000) {
        M2C_FIELD(&data_021375ac, s8 *, 0x62) = 1;
        if (M2C_FIELD(&data_021375ac, u16 *, 0x4C) == 0) {
            M2C_FIELD(&data_021375ac, s16 *, 0x60) = 0x14;
        } else {
            M2C_FIELD(&data_021375ac, s16 *, 0x60) = 0x3C;
        }
    }
    return 1;
}
