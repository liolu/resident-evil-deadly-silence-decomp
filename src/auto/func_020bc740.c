/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020bb594(M2C_UNK);                     /* extern */
M2C_UNK func_020bb780(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_021248c8;
extern void *data_027e000c;

void func_020bc740(void) {
    if (M2C_FIELD(data_027e000c, u8 *, 9) == 0x2A) {
        func_020bb594(0x2A);
        M2C_FIELD(data_027e000c, s8 *, 0xA) = 0;
    } else {
        func_020bb594(0x21);
    }
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
    func_020bb780(0, 0x400);
    M2C_FIELD(data_027e000c, M2C_UNK **, 0xC) = &data_021248c8;
}
