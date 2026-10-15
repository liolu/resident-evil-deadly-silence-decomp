/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02072ef8(M2C_UNK);

void func_02073280(s32 arg0) {
    func_02072ef8((s32) M2C_FIELD(arg0, s16 *, 0x12));
    M2C_FIELD(arg0, s16 *, 0x12) = (s16) (M2C_FIELD(arg0, s16 *, 0x12) - 1);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x12) <= 3) {
        M2C_FIELD(arg0, s8 *, 1)     = 4;
        M2C_FIELD(arg0, s16 *, 0x10) = 0;
    }
}
