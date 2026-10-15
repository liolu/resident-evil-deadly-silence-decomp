/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0209fc68();                            /* extern */
extern s32 data_027e000c;

void func_0209fc40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r4;

    temp_r4       = data_027e000c;
    data_027e000c = arg0;
    func_0209fc68(arg0, arg1, arg2, arg3);
    data_027e000c = temp_r4;
}
