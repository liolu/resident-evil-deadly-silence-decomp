/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e3fa0();       /* extern */
M2C_UNK func_020e40c0();                            /* extern */
M2C_UNK func_020ecf74();                         /* extern */
M2C_UNK func_020ed188();                         /* extern */
M2C_UNK func_020ed680();                         /* extern */
M2C_UNK func_020ed690();                         /* extern */
M2C_UNK func_020ed6d4();             /* extern */
M2C_UNK func_020edc40();                         /* extern */
M2C_UNK func_020edc50();    /* extern */
M2C_UNK func_020f269c();                 /* extern */
M2C_UNK func_020f26bc();                         /* extern */
extern M2C_UNK data_02127a3c;
extern M2C_UNK *data_02154338;

void func_020ed37c(void *arg0) {
    data_02154338 = &data_02127a3c;
    func_020ed680(arg0 + 0xC);
    func_020ed188(arg0 + 8);
    func_020f26bc(arg0 + 0x14);
    func_020ed690(arg0 + 0x10);
    func_020ecf74(arg0 + 0x4E254);
    func_020edc40(arg0 + 0x4202C);
    func_020ed6d4(arg0, 0x1E);
    func_020edc50(arg0 + 0x4202C, 0x100, 0xC0);
    func_020e40c0();
    M2C_FIELD(arg0, s32 *, 0x42028) = func_020e3fa0(0, 0, 0);
    func_020f269c(arg0 + 0x42024, M2C_FIELD(arg0, s32 *, 0x42028));
}
