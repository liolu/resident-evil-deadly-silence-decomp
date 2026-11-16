/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0211e754;
extern M2C_UNK data_02143cc0;

void func_02077ef4(void) {
    u32 k;
    u32 i;

    k = *((u8 *) &data_02143cc0 + 0xF);
    if (k == 0) {
        goto done;
    }
    i = k - 1;
    ((void (**)(void)) &data_0211e754)[i]();
done:
    return;
}
