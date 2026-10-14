/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0201e514(M2C_UNK);
void func_020559cc(M2C_UNK, M2C_UNK);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);
void func_020b3864(M2C_UNK);
void func_020b8110(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02144bc0;
extern void *data_027e000c;

void func_0201f3b4(s32 arg0) {
    s32 temp_r0;

    func_020b3864(arg0);
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 7;
    M2C_FIELD(arg0, s8 *, 0x92) = 0;
    M2C_FIELD(arg0, s16 *, 0x180) = (s16) ((M2C_FIELD(&data_02144bc0, s16 *, 0x88) & 0xFFF) - (M2C_FIELD(arg0, s16 *, 0x44) & 0xFFF));
    temp_r0 = (s32) M2C_FIELD(data_027e000c, u8 *, 0x96) >> 3;
    if ((temp_r0 == 7) || (temp_r0 == 0xA)) {
        M2C_FIELD(arg0, u16 *, 0x198) = (u16) (M2C_FIELD(arg0, u16 *, 0x198) | 0x40);
        func_0201e514(0xA);
        func_0201e514(0xD);
        func_0201e514(0xF);
    }
    if ((M2C_FIELD(arg0, u8 *, 0xA) == 4) || !(M2C_FIELD(arg0, s8 *, 0x194) & 0x7F)) {
        M2C_FIELD(arg0, s8 *, 0x91) = 2;
        func_020559cc(arg0, 0xB);
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0xF0;
    } else {
        M2C_FIELD(arg0, s8 *, 0x91) = 1;
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        func_020559cc(arg0, 0xB);
        M2C_FIELD(arg0, s16 *, 0xA6) = (s16) ((s16) M2C_FIELD(arg0, s16 *, 0xA6) >> 1);
    }
    func_02075738(0, 0x400);
    func_020b8110(0x48, 0);
}
