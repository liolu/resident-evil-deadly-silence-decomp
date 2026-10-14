/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e8b24(M2C_UNK);
void func_020fd448(M2C_UNK);

void func_020e8c68(s32 arg0) {
    if (arg0 == 0) {
        return;
    }
    if (*(M2C_UNK *)arg0 == 0) {
        return;
    }
    func_020e8b24(arg0);
    func_020fd448(arg0 + 0x24);
    *(M2C_UNK *)arg0 = 0;
}
