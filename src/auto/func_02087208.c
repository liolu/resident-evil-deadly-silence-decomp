/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 func_02088604(void);

s32 func_02087208(void *arg0, void *arg1, s32 arg2) {
    u16 v;

    v = *(u16 *) (*(u8 **) ((u8 *) arg0 + 0xC)) & 0xF;
    if (((u8 *) arg1)[5] != 0) {
        return 1;
    }
    if (arg2 != 1) {
        return 1;
    }
    if (((u8 *) arg0)[7] == 2 && v == 3) {
        if (func_02088604() != 4) {
            return 1;
        }
        return 0;
    }
    return 1;
}
