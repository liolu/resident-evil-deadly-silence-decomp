/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0211d220;

void func_02056e24(void *arg0) {
    u8 buf[0x3C];
    u8 *p;
    u32 x;

    p                  = M2C_FIELD(arg0, u8 **, 8);
    *(u8 **) (buf + 8) = p;
    x                  = M2C_FIELD(arg0, u32 *, 4);
    *(u32 *) (buf + 4) = x;
    (*(void (**)(void *))((u8 *) &data_0211d220 + (*p * 4)))(buf);
}
