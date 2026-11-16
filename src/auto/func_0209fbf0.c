/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_027e000c;
extern s32 data_027e0148;
extern s32 data_027e003c;
extern s32 data_027e009c;

M2C_UNK func_0209fc68();
M2C_UNK func_01ff8078();

void func_0209fbf0(s32 arg0) {
    func_0209fc68(data_027e000c, (u8) arg0, &data_027e0148, &data_027e003c);
    func_01ff8078(&data_027e0148, &data_027e003c, &data_027e009c);
}
