/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_021249a8;
extern M2C_UNK data_0213b890;

void func_020bd2ac(void) {
    void (**tbl)(void) = (void (**)(void)) &data_021249a8;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x21]]();
}
