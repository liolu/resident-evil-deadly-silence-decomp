/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020da8a8(M2C_UNK, M2C_UNK, s16 *, void *, void *, void *, void *, void *, void *, void *); /* extern */

s16 func_020da7a0(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s16 sp18;

    M2C_FIELD(arg0, s16 *, 2) = 1;
    if (func_020da8a8(arg1, arg2, &sp18, arg0 + 0xC, arg0 + 0xD, arg0 + 0xF, arg0 + 0xE, arg0 + 0x14, arg0 + 0x18,
                      arg0 + 0x10) < 0) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x1C) = 0;
    M2C_FIELD(arg0, s16 *, 0x26) = 0;
    M2C_FIELD(arg0, s16 *, 0x24) = (s16) M2C_FIELD(arg0, s16 *, 0x26);
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) M2C_FIELD(arg0, s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg0, s32 *, 0x30);
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_FIELD(arg0, s32 *, 0x28);
    M2C_FIELD(arg0, s32 *, 0x50) = (s32) M2C_FIELD(arg0, s8 *, 0xE);
    M2C_FIELD(arg0, s32 *, 0x54) = (s32) M2C_FIELD(arg0, s8 *, 0xF);
    M2C_FIELD(arg0, s32 *, 0x58) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
    M2C_FIELD(arg0, s32 *, 0x5C) = (s32) M2C_FIELD(arg0, s32 *, 0x3C);
    M2C_FIELD(arg0, s32 *, 0x60) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(arg0, s32 *, 0x64) = (s32) M2C_FIELD(arg0, s32 *, 0x44);
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 0x88) = 0;
    M2C_FIELD(arg0, s16 *, 0x98) = 3;
    if (M2C_FIELD(arg0, s8 *, 0xD) == 8) {
        M2C_FIELD(arg0, s16 *, 0x9C) = 1;
    } else {
        M2C_FIELD(arg0, s16 *, 0x9C) = 0;
    }
    return sp18;
}
