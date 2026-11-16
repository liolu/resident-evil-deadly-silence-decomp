/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02125d8c;
extern M2C_UNK data_0213b890;

void func_020cbce8(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02125d8c;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x20]]();
}
