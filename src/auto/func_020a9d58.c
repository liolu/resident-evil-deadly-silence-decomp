/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 func_020b39e4(void *a, s32 b);
extern u8 data_0213be00[];
extern u8 data_02147cc0[];

u8 func_020a9d58(void) {
    u8 *obj;
    u8 kind;
    u32 r4;

    obj  = *(u8 **) (data_02147cc0 + 0x53C);
    kind = obj[0];
    r4   = obj[1];
    if (kind < 2) {
        goto zero;
    }
    if (kind != 0xA) {
        goto done;
    }
    if (func_020b39e4(data_0213be00, 0x7E) == 0) {
        goto done;
    }
    if (r4 != 0) {
        goto done;
    }
    r4     = 4;
    obj    = *(u8 **) (data_02147cc0 + 0x53C);
    obj[1] = r4;
    goto done;

zero:
    r4 = 0;
done:
    return (u8) r4;
}
