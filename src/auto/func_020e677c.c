/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e6dc0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02130df8;
extern M2C_UNK data_02130e24;

void func_020e677c(void *arg0, s32 arg1) {
    if (arg0 == NULL) {
        func_020e6dc0(&data_02130df8);
        return;
    }
    if ((arg1 < 0) || (arg1 > (s32) M2C_FIELD(arg0, s32 *, 0x18))) {
        func_020e6dc0(&data_02130e24);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x14) = arg1;
}
