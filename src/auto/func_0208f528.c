/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02085fb4();                                /* extern */
M2C_UNK func_0208f834(M2C_UNK);                     /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern void *data_02137894;
extern u16 data_0213ad84;
extern M2C_UNK data_0213ae0c;

void func_0208f528(void) {
    if (data_0213ad84 == 0) {
        if ((func_02085fb4() == 0) || (M2C_FIELD(&data_0213ae0c, u8 *, 0x24) != 0)) {
            func_0208f834(0);
            func_020c46b4(0);
            return;
        }
        M2C_FIELD(data_02137894, u8 *, 4) = (u8) (M2C_FIELD(data_02137894, u8 *, 4) + 1);
        M2C_FIELD(data_02137894, s8 *, 5) = 0;
    }
}
