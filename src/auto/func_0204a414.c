/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020559cc(M2C_UNK, M2C_UNK);
M2C_UNK func_0209fbf0(M2C_UNK);

extern void *data_027e000c;
extern M2C_UNK data_027e009c;

void func_0204a414(s32 arg0, s32 arg1) {
    void *temp_r2;
    void *temp_r4;

    temp_r4 = data_027e000c;
    temp_r2 = M2C_FIELD(temp_r4, void **, 0x9C);
    if (M2C_FIELD(temp_r2, u8 *, 0x19B) == 1) {
        M2C_FIELD(temp_r2, u8 *, 0x19B) = 0U;
        func_0209fbf0(1);
        M2C_FIELD(temp_r4, s32 *, 0x30) = (s32) M2C_FIELD(&data_027e009c, s32 *, 0x14);
        M2C_FIELD(temp_r4, s32 *, 0x38) = (s32) M2C_FIELD(&data_027e009c, s32 *, 0x1C);
    }
    func_020559cc(arg0, arg1);
}
