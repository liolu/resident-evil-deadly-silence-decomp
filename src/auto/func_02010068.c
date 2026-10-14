/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200ff6c(void *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK data_027e003c;

void func_02010068(void *arg0) {
    M2C_FIELD(&data_027e003c, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(&data_027e003c, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
    func_0200ff6c(arg0, &data_027e003c, 0);
    func_0200ff6c(arg0, &data_027e003c, 1);
}
