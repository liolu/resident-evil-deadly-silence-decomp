/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02018320(void *, u8, u8, s32, M2C_UNK *, s32); /* extern */
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_027e0054;

void func_02001a0c(void *arg0, void *arg1) {
    func_02018320(arg1, M2C_FIELD(arg0, u8 *, 5), M2C_FIELD(arg0, u8 *, 6),
                  (M2C_FIELD(&data_02144bc0, s16 *, 0x88) - M2C_FIELD(arg1, s16 *, 0x44)) + 0x800, &data_027e0054, 0);
}
