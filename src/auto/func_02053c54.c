#include "m2c.h"

extern M2C_UNK data_0214813c;

void func_02053c54(void *arg0) {
    *((u8 *) ((s8 *) &data_0214813c + (M2C_FIELD(arg0, s8 *, 6) * 4))) = 2;
    M2C_FIELD(arg0, s8 *, 8)                                           = 0;
}
