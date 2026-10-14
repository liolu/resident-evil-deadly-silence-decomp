/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02076e50(M2C_UNK);
void func_020b9c98(void);

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bae8;

void func_020d08d0(void) {
    func_02076e50((s32) &data_0213bae8);
    func_02076e50(M2C_FIELD(&data_0213b890, s32 *, 0x4C));
    func_02076e50(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x20);
    func_020b9c98();
}
