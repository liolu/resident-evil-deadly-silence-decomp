/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_0200d1f4(M2C_UNK, M2C_UNK, M2C_UNK);
void func_0200e0b0(void);

extern void *data_02137298;

void func_0200b6ec(s32 arg0) {
    s32 *temp_r0_2;
    void *temp_r0;

    temp_r0   = M2C_FIELD(data_02137298, void **, 0x1414);
    temp_r0_2 = (s32 *) func_0200d1f4((s32) temp_r0, arg0, M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x88), s32 *, 0x14));
    if (M2C_FIELD((M2C_FIELD(M2C_FIELD(data_02137298, void **, 0x1414), s32 *, 0x80) + ((u32) (*temp_r0_2 << 8) >> 4)), s32 *,
                  0x14) != 0) {
        func_0200e0b0();
    }
    M2C_FIELD((M2C_FIELD(M2C_FIELD(data_02137298, void **, 0x1414), s32 *, 0x80) + ((u32) (*temp_r0_2 << 8) >> 4)), s32 *,
              0x14) = 0;
}
