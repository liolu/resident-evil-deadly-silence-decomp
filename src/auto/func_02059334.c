/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02056ea0(void *, M2C_UNK);             /* extern */
M2C_UNK func_020b3a00(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_0213db04;

s32 func_02059334(void *arg0) {
    func_02056ea0(arg0, 3);
    func_020b3a00(&data_0213db04, M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 6));
    return 7;
}
