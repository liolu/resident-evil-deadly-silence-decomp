/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020dad88(M2C_UNK);
void func_020daee4(M2C_UNK);
void func_020db01c(M2C_UNK);

void func_020dad3c(s32 arg0) {
    s16 temp_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x9C);
    if (temp_r1 == 2) {
        func_020dad88(arg0);
        return;
    }
    if (temp_r1 == 1) {
        func_020daee4(arg0);
        return;
    }
    func_020db01c(arg0);
}
