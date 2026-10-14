/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02075738(u8);                              /* extern */
M2C_UNK func_02091118(M2C_UNK *, u8);               /* extern */
M2C_UNK func_020a840c();                            /* extern */
M2C_UNK func_020adf5c(M2C_UNK);                     /* extern */
M2C_UNK func_020b51f0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02144c04;
extern M2C_UNK data_02144cc0;

s32 func_020adcf8(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_02075738((u8) (arg0 | 0x80));
    func_020adf5c(0);
    func_020a840c();
    func_020b51f0(&data_02144c04);
    if (M2C_FIELD(&data_02144cc0, u8 *, 0xAC) != 0) {
        func_02091118(&data_02144c04, M2C_FIELD(&data_02144cc0, u8 *, 5));
    }
    return temp_r4;
}
