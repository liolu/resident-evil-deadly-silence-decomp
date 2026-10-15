/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020062ac(M2C_UNK, M2C_UNK);
void func_020c00d4(M2C_UNK);

extern M2C_UNK data_0213ad98;

void func_020c0110(s32 arg0) {
    if (!(M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80)) {
        func_020062ac((s32) M2C_FIELD(arg0, u8 *, 6), arg0 + 8);
    }
    func_020c00d4(arg0);
}
