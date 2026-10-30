/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02074ef0(M2C_UNK);                         /* extern */
M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020a1db0();                            /* extern */
s32 func_020b39e4(M2C_UNK *, u16);                  /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213be00;
extern M2C_UNK data_0213be28;
extern M2C_UNK data_0213be88;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02147cc0;
extern M2C_UNK data_02148392;

s32 func_020a23fc(void *arg0) {
    if ((M2C_FIELD(&data_02147cc0, u8 *, 0x542) == 0) && (M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) == 0) &&
        !(M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x7F00) && (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0x40) &&
        (func_020b39e4(&data_0213be88, *((u16 *) ((s8 *) &data_02148392 + (M2C_FIELD(arg0, u16 *, 4) * 0xC)))) != 0)) {
        if ((M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) == 3) && (M2C_FIELD(&data_0213ad48, u8 *, 4) == 0)) {
            func_02092dd4(0xD7, 0xFF);
            return 0;
        }
        if (func_020b39e4(&data_0213be28, M2C_FIELD(arg0, u16 *, 2)) == 0) {
            if ((func_02074ef0(0x3D) >= 0) || (func_020b39e4(&data_0213be00, 0x7CU) != 0)) {
                M2C_FIELD(&data_02144cc0, void **, 0xDC) = arg0;
                M2C_FIELD(&data_02147cc0, u8 *, 0x542)   = 1U;
            } else {
                func_02092dd4(0xD8, 0xFF);
            }
        } else {
            M2C_FIELD(&data_02144cc0, void **, 0xDC) = arg0;
            func_020a1db0();
            M2C_FIELD(&data_0213ad98, u8 *, 4)     = (u8) M2C_FIELD(&data_0213ad98, u8 *, 2);
            M2C_FIELD(&data_0213ad98, u8 *, 2)     = (u8) M2C_FIELD(arg0, u16 *, 6);
            M2C_FIELD(&data_02147cc0, u8 *, 0x542) = 0x23U;
            M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x45);
        }
        goto block_14;
    }
block_14:
    return 0;
}
