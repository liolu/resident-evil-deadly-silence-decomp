/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_02122ef2;
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_0213be10;

s32 func_020b5828(s32 arg0, void *arg1) {
    if (arg0 == 0x42) {
        if (func_020b39e4(&data_0213be10, 8) == 0) {
            if ((func_020b39e4(&data_0213bde0, 0x2D) == 0) && ((M2C_FIELD(arg1, u8 *, 1) & 0x7F) == 6)) {
                return 0xC6;
            }
            if ((func_020b39e4(&data_0213bde0, 0x2E) == 0) && ((M2C_FIELD(arg1, u8 *, 1) & 0x7F) == 7)) {
                return 0xC6;
            }
            goto block_14;
        }
        if ((func_020b39e4(&data_0213bde0, 0x23) == 0) && ((M2C_FIELD(arg1, u8 *, 1) & 0x7F) == 3)) {
            return 0xC6;
        }
        if ((func_020b39e4(&data_0213bde0, 0x24) == 0) && ((M2C_FIELD(arg1, u8 *, 1) & 0x7F) == 4)) {
            return 0xC6;
        }
        goto block_14;
    }
block_14:
    if (*((u8 *) ((s8 *) &data_02122ef2 + (arg0 * 4))) == 0xFF) {
        return 0x32;
    }
    return 0xB;
}
