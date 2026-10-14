/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02018204(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fbf0(s16);                         /* extern */
extern void *data_027e000c;
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e009c;

void func_02040000(M2C_UNK arg0, M2C_UNK arg1, s16 arg2, s32 arg3) {
    M2C_FIELD(data_027e000c, s16 *, 0x196) = arg2;
    func_0209fbf0(M2C_FIELD(data_027e000c, s16 *, 0x196));
    func_02018204(arg0, arg1, 0, &data_027e009c, &data_027e0054, arg3);
}
