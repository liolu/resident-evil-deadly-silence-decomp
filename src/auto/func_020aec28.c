/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020d95b4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213aaf0;
extern M2C_UNK data_02144c04;

void func_020aec28(void) {
    M2C_FIELD(&data_0213aaf0, s16 *, 8)  = 0x7FFF;
    M2C_FIELD(&data_0213aaf0, s8 *, 0xA) = 0;
    func_020d95b4((s32) &data_02144c04, 0x1F, 0x1F, 0x1F);
}
