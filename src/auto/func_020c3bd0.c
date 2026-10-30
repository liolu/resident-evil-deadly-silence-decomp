/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c3b9c();                            /* extern */
s32 func_020f3244(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_0213b3ac;

void func_020c3bd0(void *arg0, s32 arg1) {
    func_020c3b9c();
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 0x30) = func_020f3244(&data_0213b3ac, arg1);
    }
}
