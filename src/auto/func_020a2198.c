/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_01ff83fc(M2C_UNK *, M2C_UNK, M2C_UNK *); /* extern */
M2C_UNK func_01ff87b4(s16 *, M2C_UNK *);            /* extern */
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e00bc;

void func_020a2198(s16 arg0, M2C_UNK arg1, void *arg2) {
    s16 buf[3];

    buf[2] = 0;
    buf[1] = arg0;
    buf[0] = buf[2];
    func_01ff87b4(buf, &data_027e00bc);
    func_01ff83fc(&data_027e00bc, arg1, &data_027e0054);
    M2C_FIELD(arg2, s16 *, 0) = (s16) M2C_FIELD(&data_027e0054, s32 *, 0);
    M2C_FIELD(arg2, s16 *, 2) = (s16) M2C_FIELD(&data_027e0054, s32 *, 4);
    M2C_FIELD(arg2, s16 *, 4) = (s16) M2C_FIELD(&data_027e0054, s32 *, 8);
}
