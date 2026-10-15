/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fcb08(M2C_UNK);

void func_020fd448(s32 arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 0x44);
    if (temp_r0 == 0) {
        return;
    }
    func_020fcb08(temp_r0);
    M2C_FIELD(arg0, s32 *, 0x44) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = 0;
}
