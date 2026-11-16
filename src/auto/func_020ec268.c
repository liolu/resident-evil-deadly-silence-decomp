/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020e9d88(M2C_UNK);
void func_020eccbc(s32);
M2C_UNK func_0211035c(void *, M2C_UNK, M2C_UNK);

void func_020ec268(void *arg0) {
    s32 v;

    if (arg0 == NULL) {
        return;
    }
    v = M2C_FIELD(arg0, s32 *, 4);
    if (v != 0) {
        M2C_FIELD(arg0, s32 *, 4) = 0;
        func_020eccbc(v);
    }
    v = M2C_FIELD(arg0, s32 *, 0);
    if (v != 0) {
        M2C_FIELD(arg0, s32 *, 0) = 0;
        func_020e9d88(v);
    }
    func_0211035c(arg0, 0, 0x50);
}
