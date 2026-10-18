#include "m2c.h"

extern M2C_UNK data_021375ac;

typedef struct {
    s32 f0;
    s32 f1;
    s32 f2;
} M2C_S12;

void func_020885d0(void *arg0) {
    void *temp_r0;

    temp_r0                        = M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), void **, 0x3C0);
    *(M2C_S12 *) ((s8 *) arg0 + 0) = *(M2C_S12 *) ((s8 *) temp_r0 + 0);
}
