/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ff8078(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_020182f0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fc68(void *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_027e003c;
extern M2C_UNK data_027e007c;
extern M2C_UNK data_027e009c;
extern M2C_UNK data_027e00b0;
extern M2C_UNK data_027e0148;

void func_0201ec54(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if ((s32) M2C_FIELD(arg0, s16 *, 0x192) > 0) {
        func_0209fc68(arg0, arg1, &data_027e0148, &data_027e003c);
        func_01ff8078(&data_027e0148, &data_027e003c, &data_027e009c);
        func_020182f0(0, arg2, 0, &data_027e007c, &data_027e00b0, 0);
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x192) - 1);
    }
}
