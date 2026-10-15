/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02017a94(M2C_UNK);
void func_02017bac(M2C_UNK);

void func_02015bac(s32 arg0) {
    func_02017bac(arg0);
    M2C_FIELD(arg0, s8 *, 2) = 2;
    M2C_FIELD(arg0, s8 *, 0) = 5;
    func_02017a94(arg0);
}
