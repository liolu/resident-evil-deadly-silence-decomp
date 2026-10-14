/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210c0dc(u16);                         /* extern */
M2C_UNK func_0210c0fc(u16);                         /* extern */
extern s32 data_0215a7bc;

s32 func_02109a6c(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 9:
        func_0210c0fc((u16) data_0215a7bc);
        return 0;
    case 10:
        func_0210c0dc((u16) data_0215a7bc);
        return 0;
    case 1:
        return 4;
    default:
        return 8;
    }
}
