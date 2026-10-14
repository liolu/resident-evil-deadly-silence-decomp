/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0207dbfc(M2C_UNK);
void func_02084a1c(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0207da98(s32 arg0) {
    func_02084a1c(arg0, (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 0x44), M2C_FIELD(arg0, s32 *, 0x1CC) + M2C_FIELD(arg0, s32 *, 0x1D0));
    M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) - 3);
    func_0207dbfc(arg0);
}
