/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02050aa0(M2C_UNK);
void func_020b3a24(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213be00;

void func_0204f778(s32 arg0) {
    M2C_FIELD(arg0, u16 *, 0x198) = (u16) (M2C_FIELD(arg0, u16 *, 0x198) + 1);
    if ((u32) M2C_FIELD(arg0, u16 *, 0x198) > 3U) {
        func_020b3a24((s32) &data_0213be00, 0x5B);
    }
    M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(arg0, s32 *, 0x194);
    M2C_FIELD(arg0, s8 *, 0x96) = 0;
    func_02050aa0(arg0);
}
