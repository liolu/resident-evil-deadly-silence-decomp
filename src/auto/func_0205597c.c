/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020a04b8(void *, u8, u8);              /* extern */
extern M2C_UNK data_0211d029;
extern void *data_027e000c;

void func_0205597c(u16 arg0) {
    if (arg0 != M2C_FIELD(data_027e000c, u16 *, 4)) {
        M2C_FIELD(data_027e000c, u16 *, 4) = arg0;
        func_020a04b8(data_027e000c, *((u8 *) ((s8 *) &data_0211d029 + (M2C_FIELD(data_027e000c, u8 *, 9) * 8))), (u8) arg0);
    }
}
