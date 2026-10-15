/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02082d64(M2C_UNK);
void func_02090954(M2C_UNK);

void func_02080fd8(s32 arg0) {
    if ((s32) M2C_FIELD(*(M2C_UNK *) arg0, s16 *, 0x94) <= 0) {
        func_02090954(6);
    }
    func_02082d64(arg0);
}
