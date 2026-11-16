/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02120c10;
extern M2C_UNK data_0213b2b4;

void func_0209fa6c(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02120c10;
    u8 *st             = (u8 *) &data_0213b2b4;
    tbl[st[0xb5]]();
}
