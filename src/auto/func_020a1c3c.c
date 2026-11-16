/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK func_020c46d4(s32, s32);
extern u8 data_0213ad98[];
extern u8 data_0213daa8[];
extern u8 data_0214bcc0[];

void func_020a1c3c(void) {
    u8 b;

    b = data_0213ad98[5];
    if (b & 0x80) {
        return;
    }
    if (!(b & 1)) {
        data_0214bcc0[0x7A8] = 3;
        func_020c46d4(0x17, 0);
        return;
    }
    data_0214bcc0[0x7A8]            = 0;
    *(u16 *) (data_0213daa8 + 0x74) = *(u16 *) (data_0213daa8 + 0x74) | 0x45;
}
