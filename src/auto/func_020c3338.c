/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02005e44(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_021061d8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b2b4;

void func_020c3338(void) {
    func_021061d8(M2C_FIELD(&data_0213b2b4, s32 *, 0xC8), 0, 0xF00);
    func_02005e44(0, M2C_FIELD(&data_0213b2b4, s32 *, 0xC8), 0, 0xF00);
}
