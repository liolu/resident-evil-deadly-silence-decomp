/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s16 func_0201fb60(u8 *arg0, s32 arg1) {
    s16 t;

    t                      = *(s16 *) (arg0 + 0x44) + (s16) * (s16 *) (arg0 + 0x180) * (s16) arg1;
    *(s16 *) (arg0 + 0x44) = t;
    *(s16 *) (arg0 + 0xa8) = (s16) (*(s16 *) (arg0 + 0xa8) - arg1);
    if (*(s16 *) (arg0 + 0xa8) <= 0) {
        arg0[0x93]             = 3;
        *(s16 *) (arg0 + 0xa8) = 4;
    }
    return *(s16 *) (arg0 + 0x180);
}
