#include "engine.h"
#include "m2c.h"

M2C_UNK func_020d9650(void);

void func_0201c7f8(s32 arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x92) != 0) {
        M2C_FIELD(arg0, u8 *, 0x92) = 0U;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
    }
    func_020d9650();
}
