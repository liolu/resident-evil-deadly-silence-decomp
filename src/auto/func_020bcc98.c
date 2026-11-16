/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890[];

void func_020bcc98(s32 arg0, s32 arg1) {
    s32 val;
    u8 *base;

    if (arg1 == 0) {
        val = 0x8000;
    } else {
        val = -0x8000;
    }
    base                = *(u8 **) (data_0213b890 + 0x4C) + 0xC + arg0 * 0x1C;
    *(s32 *) base       = val;
    *(s32 *) (base + 4) = val;
}
