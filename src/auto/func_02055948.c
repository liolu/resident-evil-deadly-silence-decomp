/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02091184(void *, M2C_UNK);             /* extern */
M2C_UNK func_020a04b8(void *, u8, M2C_UNK);         /* extern */
extern M2C_UNK data_0211d029;

void func_02055948(void *arg0, M2C_UNK arg1) {
    func_020a04b8(arg0, *((u8 *) ((s8 *) &data_0211d029 + (M2C_FIELD(arg0, u8 *, 9) * 8))), arg1);
    func_02091184(arg0, 0);
}
