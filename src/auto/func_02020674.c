/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0201e954(M2C_UNK);

void func_02020674(s32 arg0) {
    func_0201e954(arg0);
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0x21) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 4;
        M2C_FIELD(arg0, s8 *, 0x96) = 0;
    }
}
