/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02143ce8;
extern M2C_UNK data_02143d0c;
extern M2C_UNK data_0214bcc0;

void func_02017c18(void) {
    M2C_FIELD(&data_02143cc0, s32 *, 0x78) = (s32) M2C_FIELD(((M2C_FIELD(&data_0213ad98, u8 *, 2) * 0x2C) + M2C_FIELD(&data_0214bcc0, s32 *, 0x7AC)), s32 *, 0x90);
    M2C_FIELD(&data_02143cc0, M2C_UNK **, 0x70) = &data_02143ce8;
    M2C_FIELD(&data_02143cc0, M2C_UNK **, 0x74) = &data_02143d0c;
}
