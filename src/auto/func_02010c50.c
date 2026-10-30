/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02010a7c();                            /* extern */
M2C_UNK func_02010ba4();                            /* extern */
extern void *data_0213ad2c;

void func_02010c50(s32 arg0) {
    if ((u32) M2C_FIELD(data_0213ad2c, u8 *, 8) < 6U) {
        func_02010ba4(arg0);
        return;
    }
    func_02010a7c(arg0);
}
