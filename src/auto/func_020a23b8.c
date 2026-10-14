/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020796fc(s32);                         /* extern */
M2C_UNK func_020b37ac(void *);                      /* extern */
M2C_UNK func_020b502c();                            /* extern */
extern M2C_UNK data_0213ad98;

s32 func_020a23b8(void *arg0) {
    func_020b502c();
    func_020b37ac(M2C_FIELD(arg0, void **, 8));
    func_020796fc(M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 8) - 0x4E);
    M2C_FIELD(&data_0213ad98, u8 *, 0x13) = (u8) M2C_FIELD(M2C_FIELD(arg0, void **, 8), u8 *, 8);
    return 0;
}
