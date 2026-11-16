#include "m2c.h"

extern M2C_UNK func_0207d850;
extern M2C_UNK func_0207e58c;
extern M2C_UNK func_0207f5c8;
extern M2C_UNK func_02080784;
extern M2C_UNK func_02082000;
extern M2C_UNK func_020838ec;

void func_020856a4(void *arg0) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 9);
    switch (temp_r1) {
        case 0:
        case 5:
        case 6:
        case 7:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_0207d850;
            return;
        case 1:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_0207e58c;
            return;
        case 2:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_0207f5c8;
            return;
        case 3:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_02080784;
            return;
        case 4:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_02082000;
            return;
        default:
            M2C_FIELD(arg0, M2C_UNK **, 0x2C) = &func_020838ec;
            return;
    }
}
