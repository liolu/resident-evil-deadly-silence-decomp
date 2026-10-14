/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213e394;

void func_02092744(void) {
    if (M2C_FIELD(&data_0213e394, s16 *, 0xE) == 0) {
        if ((M2C_FIELD(&data_0213ae4c, u8 *, 2) == 0) && !(M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x50)) {
            return;
        }
        M2C_FIELD(&data_0213e394, s8 *, 1) = 1;
        return;
    }
    M2C_FIELD(&data_0213e394, s16 *, 0xE) = (s16) (M2C_FIELD(&data_0213e394, s16 *, 0xE) - M2C_FIELD(&data_0213e394, u8 *, 5));
    if ((s32) M2C_FIELD(&data_0213e394, s16 *, 0xE) <= 0) {
        M2C_FIELD(&data_0213e394, s8 *, 1) = 1;
    }
}
