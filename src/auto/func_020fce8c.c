/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fcf58(M2C_UNK, M2C_UNK);
M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);
void func_02106854(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_020fce8c(s32 arg0) {
    s32 temp_r6;

    if (((s32) (M2C_FIELD(arg0, s32 *, 0x24) << 0x1E) >> 0x1F) == 0) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x38) != 0) {
        do {
            temp_r6 = func_021054ac();
            func_020fcf58(arg0, 1);
            func_021054c0(temp_r6);
        } while (M2C_FIELD(arg0, s32 *, 0x38) != 0);
    }
    func_02106854(M2C_FIELD(arg0, s32 *, 0x44), 0, 1 << M2C_FIELD(arg0, s32 *, 0x40), 0);
}
