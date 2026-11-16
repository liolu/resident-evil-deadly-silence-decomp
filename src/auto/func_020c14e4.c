/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02124f00;
extern M2C_UNK data_0213b890;

void func_020c14e4(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02124f00;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x21]]();
}
