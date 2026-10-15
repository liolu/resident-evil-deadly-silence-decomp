/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020834dc(M2C_UNK);
void func_02084a1c(M2C_UNK, M2C_UNK, M2C_UNK);

void func_02081790(s32 arg0) {
    func_020834dc(arg0);
    func_02084a1c(arg0, (s32) (u16) (M2C_FIELD(*(M2C_UNK *) arg0, s16 *, 0x44) ^ 0x800), 0x30);
}
