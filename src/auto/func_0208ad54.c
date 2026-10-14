/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0208a4e4(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0208ad54(s32 arg0) {
    func_0208a4e4((s32) M2C_FIELD(arg0, u8 *, 0x2C2), arg0 + 0x2C4, arg0 + 0x2FC);
    M2C_FIELD(arg0, s8 *, 0x2F8) = 1;
    M2C_FIELD(arg0, s8 *, 0x2F9) = 8;
}
