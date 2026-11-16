/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_021249b4;
extern M2C_UNK data_0213b890;

void func_020bd40c(void) {
    void (**tbl)(void) = (void (**)(void)) &data_021249b4;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x20]]();
}
