/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0210616c(M2C_UNK, M2C_UNK);

s32 func_02100b0c(s32 arg0) {
    if (*(s32 *)0x04000600 & 0x08000000) {
        return -1;
    }
    func_0210616c(0x04000680, arg0);
    return 0;
}
