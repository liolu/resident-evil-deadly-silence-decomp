/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0211ff5c;
extern M2C_UNK data_0213b890;

void func_0208e6ac(void) {
    void (**tbl)(void) = (void (**)(void)) &data_0211ff5c;
    u8 *st             = (u8 *) &data_0213b890;
    tbl[st[0x54]]();
}
