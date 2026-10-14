/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02076e50(M2C_UNK);

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bae8;

void func_020ccf70(void) {
    func_02076e50((s32) &data_0213bae8);
    func_02076e50(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x18);
}
