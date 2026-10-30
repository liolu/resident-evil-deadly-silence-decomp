/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200ef34();                            /* extern */
M2C_UNK func_020769b0();                      /* extern */
M2C_UNK func_02076bb4();                         /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213af7c;

s32 func_0207311c(s32 *arg0) {
    if (data_0213ad84 != 0) {
        return 2;
    }
    M2C_FIELD(&data_0213af7c, s16 *, 0x1E) = 0xFF;
    *arg0                                  = 0;
    func_02076bb4(((s8 *) arg0 + 4));
    func_020769b0(((s8 *) arg0 + 5));
    func_0200ef34();
    return 2;
}
