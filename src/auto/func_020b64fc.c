#include "m2c.h"

extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213af8c;

void func_020b64fc(s32 arg0) {
    *((u8 *) ((s8 *) &data_0213af8c + (arg0 * 4))) = 0;
    M2C_FIELD(&data_0213af7c, u16 *, 0x1E)         = (u16) (M2C_FIELD(&data_0213af7c, u16 *, 0x1E) & ~(1 << (arg0 + 3)));
}
