/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_01ff8078(void *, void *, void *);         /* extern */
void func_020182f0(s32, s32, s32, void *, s32, s32); /* extern */
void func_0209fc40(void *, s32, void *, void *);    /* extern */
extern M2C_UNK data_02144c04;
extern M2C_UNK data_027e009c;

void func_0204ab04(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8[9];
    s32 sp2C[4];

    func_0209fc40(&data_02144c04, arg0, sp8, sp2C);
    func_01ff8078(sp8, sp2C, &data_027e009c);
    func_020182f0(0, arg1, 0, &data_027e009c, arg2, 0);
}
