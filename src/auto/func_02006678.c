#include "m2c.h"
#include "engine.h"

M2C_UNK func_0200d1f4(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_02137298;

void func_02006678(s32 arg0) {
    void *temp_r0;

    temp_r0 = M2C_FIELD(data_02137298, void **, 0x1414);
    func_0200d1f4((s32) temp_r0, arg0, M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x88), s32 *, 0x24));
}
