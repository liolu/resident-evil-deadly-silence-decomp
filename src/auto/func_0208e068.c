/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u32 data_0211fd34[];
extern u32 data_0211fdd4[];

s32 func_0208e068(u32 *arg0) {
    u8 i;

    i = 0;
    while (i < 12) {
        if (data_0211fd34[i] > *arg0) {
            break;
        }
        i++;
    }
    return data_0211fdd4[i + 23];
}
