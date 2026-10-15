/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020d7194(M2C_UNK);
void func_020d880c(M2C_UNK);
void func_02105528(void);

extern M2C_UNK data_02126d58;
extern M2C_UNK (*data_0213ad20)(M2C_UNK *, u16);
extern M2C_UNK data_02141cc0;

s32 func_020d7278(void) {
    if (M2C_FIELD(&data_02141cc0, s32 *, 0x40) != 7) {
        func_02105528();
    }
    func_020d880c(1);
    M2C_FIELD(&data_02141cc0, u16 *, 0x5C) = (u16) func_020d7194((s32) M2C_FIELD(&data_02141cc0, u16 *, 0x60));
    if (data_0213ad20 != NULL) {
        data_0213ad20(&data_02126d58, M2C_FIELD(&data_02141cc0, u16 *, 0x5C));
    }
    return (s32) M2C_FIELD(&data_02141cc0, u16 *, 0x5C);
}
