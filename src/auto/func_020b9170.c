/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02123df0;
extern M2C_UNK data_0213b890;

void func_020b9170(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02123df0;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x20]]();
}
