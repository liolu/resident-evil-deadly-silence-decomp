/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020306d0(M2C_UNK);                     /* extern */
M2C_UNK func_02090b70(s32, M2C_UNK);                /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, u8);               /* extern */
extern s32 data_0213733c;
extern M2C_UNK data_0213db04;
extern void *data_027e000c;

void func_020307fc(void) {
    if (func_0209109c(0, 0x200, 7) != 0) {
        func_020b3a24(&data_0213db04, M2C_FIELD(data_027e000c, u8 *, 0xBF));
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 7;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
    func_02090b70(data_0213733c, 0);
    func_020306d0(6);
}
