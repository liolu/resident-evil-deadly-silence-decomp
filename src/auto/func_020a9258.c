/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020ac19c();                            /* extern */
M2C_UNK func_020ac214(M2C_UNK);                     /* extern */
extern u16 data_0213ad98;

void func_020a9258(void *arg0) {
    if (data_0213ad98 != 0x1005) {
        func_020ac214(0);
        return;
    }
    if ((u32) (M2C_FIELD(arg0, s32 *, 0x34) + 0x1388) >= 0xBB8U) {
        func_020ac214(0);
        return;
    }
    func_020ac19c();
}
