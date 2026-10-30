/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0203a730();                            /* extern */
M2C_UNK func_0203a974();                            /* extern */
M2C_UNK func_0203ace4();                            /* extern */
extern void *data_027e000c;

void func_0203d960(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x92);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_0203a974();
            return;
        case 1:
            func_0203ace4();
            return;
        case 2:
            func_0203a730();
            return;
    }
}
