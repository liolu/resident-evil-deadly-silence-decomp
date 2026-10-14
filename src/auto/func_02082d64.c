/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020823b4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02083d28(M2C_UNK);

void func_02082d64(s32 arg0) {
    void *temp_r1;

    func_020823b4(arg0, 0xB, 0, 0);
    func_02083d28(arg0);
    M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0x34);
    M2C_FIELD(arg0, s32 *, 0x1CC) = 0x10;
    temp_r1 = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
}
