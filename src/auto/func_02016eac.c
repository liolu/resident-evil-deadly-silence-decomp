/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02016a94(M2C_UNK);

void func_02016eac(s32 arg0) {
    func_02016a94(arg0);
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) (M2C_FIELD(arg0, s16 *, 0x12) - 0x18);
}
