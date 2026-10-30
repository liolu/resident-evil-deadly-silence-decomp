/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020f82d0(s32);                         /* extern */

void func_02049d38(void *arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), u8 *, 0x19A) != 0x1F) {
        func_020f82d0(M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 *, 0xC));
    }
}
