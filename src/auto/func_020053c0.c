/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020df100(s32);                         /* extern */
extern void *data_02137264;

void func_020053c0(s8 *arg0) {
    if (*arg0 != 0) {
        func_020df100(M2C_FIELD(data_02137264, s32 *, 0x540));
    }
}
