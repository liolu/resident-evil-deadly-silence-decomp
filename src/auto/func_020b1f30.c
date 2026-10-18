#include "m2c.h"

extern M2C_UNK data_0212255c;
extern M2C_UNK data_02144c04;

u8 func_020b1f30(void *arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK **, 4) = &data_02144c04;
    return ((s8 *) &data_0212255c)[M2C_FIELD(arg0, u8 *, 1)];
}
