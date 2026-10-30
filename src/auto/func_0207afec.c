/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207ae38();                            /* extern */
M2C_UNK func_0207aec4();                            /* extern */
M2C_UNK func_0207c828();                            /* extern */
extern void *data_027e000c;

void func_0207afec(void **arg0) {
    u8 temp_r1;

    data_027e000c = *arg0;
    temp_r1       = M2C_FIELD(*arg0, u8 *, 0x90);
    switch (temp_r1) {                              /* irregular */
        case 0:
            func_0207aec4(arg0);
            return;
        case 1:
            func_0207ae38(arg0);
            return;
        case 2:
            func_0207c828(arg0);
            return;
    }
}
