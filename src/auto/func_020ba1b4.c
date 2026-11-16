#include "m2c.h"

extern u8 data_0213b890[];
extern u8 data_02147cc0[];

void func_020ba1b4(void) {
    s8 *p            = *(s8 **) (data_0213b890 + 0x4C);
    u8 *t            = *(u8 **) (data_02147cc0 + 0x538);
    data_0213b890[9] = t[p[1] * 2];
}
