/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_021212c0;
extern M2C_UNK data_0214bcc0;

void func_020a1cd0(void) {
    u32 k;
    u32 i;

    k = *((u8 *) &data_0214bcc0 + 0x7A8);
    if (k == 0) {
        goto done;
    }
    i = k - 1;
    ((void (**)(void)) &data_021212c0)[i]();
done:
    return;
}
