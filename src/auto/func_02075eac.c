/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a04f0(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_020f8360(s32, M2C_UNK);                /* extern */
M2C_UNK func_020f8678(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK data_0214dcc0;
extern M2C_UNK data_0214e5f0;

void func_02075eac(void) {
    func_020a04f0(&data_0214e5f0, 0x16);
    func_020f8678(M2C_FIELD(M2C_FIELD(&data_0214dcc0, void **, 0x930), s32 *, 0xC), 1, 0x3F000000);
    func_020f8360(M2C_FIELD(M2C_FIELD(&data_0214dcc0, void **, 0x930), s32 *, 0xC), 7);
}
