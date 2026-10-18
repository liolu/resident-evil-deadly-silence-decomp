/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02124cf1;
extern M2C_UNK data_0213b890;

u8 func_020beec0(void) {
    return ((s8 *) &data_02124cf1)[(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x13) * 0xC)];
}
