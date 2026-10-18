/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056ea0(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_0211d1b4;

u8 func_02058d0c(void *arg0) {
    u8 temp_r4;

    temp_r4 = *M2C_FIELD(arg0, u8 **, 8);
    func_02056ea0(arg0, 4);
    return ((s8 *) &data_0211d1b4)[temp_r4];
}
