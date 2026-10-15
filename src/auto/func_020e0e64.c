/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e03b0(void);
void func_020e03bc(void);
void func_020e0c98(M2C_UNK);

void func_020e0e64(s32 arg0) {
    func_020e0c98(arg0);
    func_020e03bc();
    if (M2C_FIELD(arg0, s8 *, 0x49) == 1) {
        M2C_FIELD(arg0, s8 *, 0x46) = 1;
    }
    M2C_FIELD(arg0, s8 *, 0x45) = 0;
    func_020e03b0();
}
