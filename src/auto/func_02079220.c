/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_02079220(void) {
    M2C_FIELD(&data_0213b890, u8 *, 0xA4) = (u8) M2C_FIELD(&data_0213b890, u8 *, 0xA2);
    M2C_FIELD(&data_0213b890, u8 *, 0xA5) = (u8) M2C_FIELD(&data_0213b890, u8 *, 0xA3);
}
