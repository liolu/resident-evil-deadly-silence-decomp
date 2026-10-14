/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020038b8(M2C_UNK);
void func_0200f768(M2C_UNK);
void func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020c4798(M2C_UNK);

extern M2C_UNK data_02126798;
extern M2C_UNK data_0213b890;

void func_020d5200(void) {
    func_0200f768(9);
    func_020038b8((s32) &data_02126798);
    M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x78;
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & ~0x1F00) | 0x1800;
    func_020c4798(1);
    func_0206fcf8(0, 2, 0, 0x80);
}
