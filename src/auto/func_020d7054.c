/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e120(M2C_UNK *);                       /* extern */
extern M2C_UNK func_020d7100;

void func_020d7054(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        func_020d87f0();
        func_020d880c(0xA);
        return;
    }
    if (func_0210e120(&func_020d7100) != 0) {
        func_020d87f0();
        func_020d880c(0xA);
        return;
    }
    func_020d880c(1);
}
