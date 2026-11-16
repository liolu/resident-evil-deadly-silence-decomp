/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern void *data_0214d068[];
extern void *data_0214dbec[];

s32 func_020b3f7c(void) {
    u8 *src;
    u8 *obj;
    u8 temp_r1;

    src           = data_0213daa8;
    data_0213daa8 = src + 6;
    temp_r1       = src[1];
    if (temp_r1 < 0x80) {
        obj = data_0214d068[temp_r1];
    } else {
        obj = data_0214dbec[temp_r1 & 0x7F];
    }
    if (obj[8] != 0) {
        *(s16 *) (obj + 0x42) = *(s16 *) (src + 2);
        *(s16 *) (obj + 0x46) = *(s16 *) (src + 4);
    }
    return 1;
}
