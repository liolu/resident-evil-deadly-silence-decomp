/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02016a94(void *);                      /* extern */
M2C_UNK func_02018204(u8, u8, s16, s32, M2C_UNK *, s32); /* extern */
extern M2C_UNK data_027e0054;

void func_020169b8(void *arg0) {
    M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    func_02018204(M2C_FIELD(arg0, u8 *, 4), M2C_FIELD(arg0, u8 *, 5), M2C_FIELD(arg0, s16 *, 0x16), 0, &data_027e0054, 0);
    func_02016a94(arg0);
}
