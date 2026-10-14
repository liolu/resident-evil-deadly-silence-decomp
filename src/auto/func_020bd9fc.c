/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02076f18(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020bd9fc(void) {
    func_02076f18(M2C_FIELD(&data_0213b890, s32 *, 0x258), 0x1E, 0);
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
}
