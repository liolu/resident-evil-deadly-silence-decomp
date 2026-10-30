/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_0213be88;
extern M2C_UNK data_02143cc0;

void func_020b68dc(void) {
    if ((M2C_FIELD(&data_0213ad98, u8 *, 1) == 0x15) &&
        ((M2C_FIELD(&data_0213ad98, u8 *, 0) == 0) || (M2C_FIELD(&data_0213ad98, u8 *, 0) == 5)) &&
        (func_020b39e4(&data_0213be88, 0) == 0) && (func_020b39e4(&data_0213be88, 1) == 0)) {
        if (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) == 0) {
            if (func_020b39e4(&data_0213bde0, 0x20) != 0) {
                return;
            }
            goto block_11;
        }
        if ((func_020b39e4(&data_0213bde0, 0x29) == 0) ||
            ((func_020b39e4(&data_0213bde0, 7) == 0) && (func_020b39e4(&data_0213bde0, 0x5F) == 0))) {
        block_11:
            func_020b82fc(2);
        }
    }
}
