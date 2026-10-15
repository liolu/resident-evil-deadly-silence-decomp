/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad48;

void func_020779f4(void) {
    func_021061d8((s32) &data_0213ad48, 0, 0xC);
    M2C_FIELD(&data_0213ad48, s8 *, 8)   = 1;
    M2C_FIELD(&data_0213ad48, s8 *, 9)   = 1;
    M2C_FIELD(&data_0213ad48, s8 *, 0xA) = 1;
    M2C_FIELD(&data_0213ad48, s8 *, 3)   = 1;
}
