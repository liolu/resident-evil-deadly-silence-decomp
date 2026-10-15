/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fcb94(M2C_UNK);
void func_0210694c(M2C_UNK, M2C_UNK);
void func_02106a08(M2C_UNK);

void func_020fcc24(s32 arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x2C) == 2) {
        func_0210694c((s32) M2C_FIELD(arg0, u8 *, 0x3C), -0x2D3);
    }
    func_02106a08((s32) M2C_FIELD(arg0, u8 *, 0x3C));
    func_020fcb94(arg0);
}
