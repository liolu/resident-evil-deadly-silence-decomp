/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020b8324(M2C_UNK);
void func_020c4798(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020a4a34(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 2) = 0x14;
    func_020c4798(2);
    func_020b8324(0xD);
}
