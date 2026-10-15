/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e40e4(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021304f4;
extern M2C_UNK data_02130500;
extern M2C_UNK data_0213051c;
extern M2C_UNK data_02130528;

void func_020e3c98(s32 arg0) {
    if (arg0 == 0) {
        func_020e40e4((s32) &data_021304f4, (s32) &data_02130500);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        func_020e40e4((s32) &data_0213051c, (s32) &data_02130528);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0xC)  = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) M2C_FIELD(arg0, s32 *, 0x20);
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x18) = 0;
    M2C_FIELD(arg0, s32 *, 0x28) = 0;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}
