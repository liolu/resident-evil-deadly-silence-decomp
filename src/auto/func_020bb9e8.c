/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020a0100(M2C_UNK);
void func_020a04c8(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_020bb9e8(void) {
    void *temp_r4;

    func_020a04c8((s32) (data_027e000c + 0x188), 0x73);
    temp_r4 = M2C_FIELD(data_027e000c, void **, 0x188);
    M2C_FIELD(temp_r4, s32 *, 0x14) = func_020a0100(1);
}
