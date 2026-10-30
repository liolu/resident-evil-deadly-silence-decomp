/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_021061d8();    /* extern */
M2C_UNK func_0210626c();     /* extern */
s16 func_02110048();          /* extern */
extern M2C_UNK data_02136eb0;
extern M2C_UNK data_0213705c;

void func_0200426c(s8 arg0, s32 arg1, s8 arg2, void *arg3) {
    func_021061d8(arg3, 0, 0x20);
    func_0210626c(M2C_FIELD(&data_02136eb0, s32 *, 0) + 0x20, arg3 + 0x10, 0xE);
    M2C_FIELD(arg3, s8 *, 4)  = arg0;
    M2C_FIELD(arg3, s8 *, 5)  = arg2;
    M2C_FIELD(arg3, s32 *, 0) = arg1;
    M2C_FIELD(arg3, s16 *, 6) = func_02110048(&data_0213705c, arg3, 6U);
    func_0210626c(arg3, arg3 + 8, 8);
    if (arg2 == 1) {
        M2C_FIELD(arg3, s16 *, 0x1E) = func_02110048(&data_0213705c, M2C_FIELD(&data_02136eb0, void **, 0x3AC),
                                                     (u32) (M2C_FIELD(&data_02136eb0, s32 *, 0x3B0) << 8) >> 8);
    }
}
