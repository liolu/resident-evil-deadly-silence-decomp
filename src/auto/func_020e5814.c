/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e59b4(M2C_UNK);
void func_020e5e0c(M2C_UNK);

extern M2C_UNK data_02130bd0;
extern M2C_UNK data_02130bec;

void func_020e5814(s32 arg0) {
    M2C_UNK (*temp_r1)(s32);

    if (arg0 == 0) {
        func_020e5e0c((s32) &data_02130bd0);
        return;
    }
    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), M2C_UNK (**)(s32), 0x14);
    if (temp_r1 != NULL) {
        temp_r1(M2C_FIELD(arg0, s32 *, 4));
        func_020e59b4(arg0);
        return;
    }
    func_020e5e0c((s32) &data_02130bec);
}
