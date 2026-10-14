/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020df358(M2C_UNK);
void func_020e17a4(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020e2c04(s32 arg0) {
    if (func_020df358(M2C_FIELD(arg0, s32 *, 4)) == 1) {
        func_020e17a4(arg0, 0, (s32) M2C_FIELD(arg0, s16 *, 0x42));
        return;
    }
    func_020e17a4(arg0, 0, (s32) M2C_FIELD(arg0, s16 *, 0x42));
    func_020e17a4(arg0, 1, (s32) M2C_FIELD(arg0, s16 *, 0x44));
}
