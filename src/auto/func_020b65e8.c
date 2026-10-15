#include "engine.h"
#include "m2c.h"

void func_020b64d0(void);

extern M2C_UNK data_0213af7c;

void func_020b65e8(void) {
    M2C_FIELD(&data_0213af7c, u16 *, 0x1E) = (u16) (M2C_FIELD(&data_0213af7c, u16 *, 0x1E) << 8);
    func_020b64d0();
}
