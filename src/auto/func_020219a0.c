/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_020219a0(s32 arg0) {
    u8 temp_r0;
    u8 temp_r1;

    M2C_FIELD(arg0, s8 *, 0xA0) = 0;
    temp_r1 = M2C_FIELD(arg0, u8 *, 0xA);
    switch (temp_r1) {                              /* irregular */
    case 5:
        temp_r0 = M2C_FIELD(arg0, u8 *, 0xA1);
        if (temp_r0 == 0x10) {
            M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) - 0x20);
        } else if (temp_r0 == 0xF) {
            M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x20);
        }
        func_020559cc(arg0, 0x19);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x41;
        M2C_FIELD(arg0, s16 *, 0x184) = 0x12C;
        M2C_FIELD(arg0, s16 *, 0x186) = -0x28;
        break;
    case 6:
        M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 6);
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x41;
        M2C_FIELD(arg0, s16 *, 0x184) = 0x1E0;
        M2C_FIELD(arg0, s16 *, 0x186) = -0x28;
        func_020559cc(arg0, 6);
        M2C_FIELD(arg0, s16 *, 0x196) = 5;
        M2C_FIELD(arg0, s8 *, 0x96) = 1;
        break;
    case 7:
        M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 4);
        func_020559cc(arg0, 7);
        M2C_FIELD(arg0, s8 *, 0xA0) = 0xA;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x104;
        M2C_FIELD(arg0, s16 *, 0x184) = 0x190;
        M2C_FIELD(arg0, s16 *, 0x186) = -0x28;
        M2C_FIELD(arg0, s16 *, 0x196) = 5;
        M2C_FIELD(arg0, s8 *, 0x96) = 1;
        break;
    }
    M2C_FIELD(arg0, s8 *, 0x91) = 3;
    M2C_FIELD(arg0, s8 *, 0x98) = 3;
    M2C_FIELD(arg0, s16 *, 0xA8) = 8;
    M2C_FIELD(arg0, s16 *, 0x18C) = 0;
    M2C_FIELD(arg0, s16 *, 0x192) = 0;
}
