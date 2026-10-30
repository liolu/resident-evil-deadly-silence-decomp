/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02056fb0(M2C_UNK);                     /* extern */
M2C_UNK func_0206225c();                            /* extern */
M2C_UNK func_020624d0();                            /* extern */
M2C_UNK func_02092bac();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b67e8();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213be88;

void func_02062584(void) {
    func_02056fb0(0);
    func_02056fb0(2);
    func_020b67e8();
    func_02092bac();
    if (((u32) M2C_FIELD(&data_0213ad98, u8 *, 7) < 8U) && (func_020b39e4(&data_0213be88, 0xE) != 0)) {
        func_020624d0();
        return;
    }
    func_0206225c();
}
