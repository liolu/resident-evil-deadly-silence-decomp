/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02120230;
extern M2C_UNK data_0213e394;

void func_020925c8(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02120230;
    u8 *st             = (u8 *) &data_0213e394;
    tbl[st[0x2]]();
}
