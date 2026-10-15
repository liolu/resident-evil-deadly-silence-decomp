/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020a9f08(M2C_UNK);
void func_020ac2a4(M2C_UNK);

void func_020a9f5c(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x93) = 9;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    func_020ac2a4(1);
    func_020a9f08(arg0);
}
