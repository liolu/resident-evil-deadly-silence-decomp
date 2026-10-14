/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ff8078(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_02018260(u8, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_0209fc40(void *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_027e003c;
extern M2C_UNK data_027e00bc;
extern M2C_UNK data_027e0148;

void func_02018320(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4, u8 arg5) {
    func_0209fc40(arg0, 0, &data_027e0148, &data_027e003c);
    func_01ff8078(&data_027e0148, &data_027e003c, &data_027e00bc);
    func_02018260(M2C_FIELD(arg0, u8 *, 9), arg1, arg2, arg3, &data_027e00bc, arg4, (s32) arg5);
}
