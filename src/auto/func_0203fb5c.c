/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0203e704();                            /* extern */
M2C_UNK func_0203e914();                            /* extern */
extern void *data_027e000c;

void func_0203fb5c(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x92);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_0203e914();
            return;
        case 3:
            func_0203e704();
            return;
    }
}
