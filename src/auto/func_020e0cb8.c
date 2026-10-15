/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e03b0(void);
void func_020e03bc(void);
void func_020e0d10(M2C_UNK);

s32 func_020e0cb8(s32 arg0) {
    func_020e03bc();
    func_020e0d10(arg0);
    M2C_FIELD(arg0, s32 *, 0x5C) = 0xFFFFF;
    func_020e03b0();
    return 1;
}
