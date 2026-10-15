/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0201e954(M2C_UNK);

void func_02020940(s32 arg0) {
    func_0201e954(arg0);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
    if (M2C_FIELD(arg0, s16 *, 0xA8) == 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 0xC;
    }
}
