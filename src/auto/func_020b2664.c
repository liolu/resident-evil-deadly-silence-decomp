/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213bf4a[];
extern u8 *data_0213daa8;

s32 func_020b2664(void) {
    u8 *rec;

    rec                                     = data_0213daa8;
    data_0213daa8                           = rec + 4;
    (data_0213bf4a + (rec[1] << 5))[rec[2]] = rec[3];
    return 1;
}
