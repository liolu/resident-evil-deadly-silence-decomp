/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020a1d74();                            /* extern */
s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, u16);              /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213be00;
extern M2C_UNK data_0213be28;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_02147cc0;

M2C_UNK *func_020a1e80(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if (var_r0 == 0) {
        if (!(M2C_FIELD(&data_0213ad98, u8 *, 5) & 1)) {
            func_020b3a24(&data_0213be28, M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xDC), u16 *, 2));
            func_020a1d74();
            if (func_020b39e4(&data_0213be00, 0x7C) != 0) {
                M2C_FIELD(&data_0213ad98, s8 *, 6) = 0xD;
            } else {
                M2C_FIELD(&data_0213ad98, s8 *, 6) = 0x3D;
            }
            func_02092dd4(0xC3, 0xFF);
        }
        var_r0                                       = (s32) &data_02147cc0;
        M2C_FIELD((s32) &data_02147cc0, s8 *, 0x542) = 0;
    }
    return (M2C_UNK *) var_r0;
}
