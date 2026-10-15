/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e314c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020e3180(M2C_UNK, M2C_UNK, M2C_UNK);

void func_020dbeec(s32 arg0) {
    func_020e3180(M2C_FIELD(arg0, s32 *, 8), arg0 + 0xAC, arg0 + 0xB0);
    func_020e314c(M2C_FIELD(arg0, s32 *, 8), (s32) M2C_FIELD(arg0, s16 *, 0xA6), (s32) M2C_FIELD(arg0, s16 *, 0xA8),
                  (s32) M2C_FIELD(arg0, s16 *, 0xAA));
}
