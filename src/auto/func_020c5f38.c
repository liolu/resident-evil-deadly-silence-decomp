/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c5f38(void) {
    if (!(M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x18), u8 *, 0xA) & 0x20)) {
        return;
    }
    *M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 **, 0xFC)                    = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 **, 0xFC), s8 *, 1) = 0;
}
