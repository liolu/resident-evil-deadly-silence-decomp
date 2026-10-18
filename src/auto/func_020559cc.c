/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a0490(void *, u8, M2C_UNK);         /* extern */
extern M2C_UNK data_0211d029;

void func_020559cc(void *arg0, M2C_UNK arg1) {
    func_020a0490(arg0, *((u8 *) ((s8 *) &data_0211d029 + (M2C_FIELD(arg0, u8 *, 9) * 8))), arg1);
}
