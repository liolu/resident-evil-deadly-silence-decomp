/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 func_0208495c(u8);
extern s32 func_02088580(void);
extern void func_0208486c(u8);

void func_0208487c(u8 *arg0) {
    u8 *list;
    u8 *map;
    u8 i;
    s8 v;

    list = (u8 *) func_0208495c(arg0[0x30]) + 8;
    map  = (u8 *) func_02088580() + 0xFC;
    i    = 0;
    while (i < 8) {
        v = (s8) list[i];
        if (v < 0 || v > 0x20) {
            return;
        }
        if (arg0[4] == map[v]) {
            func_0208486c((u8) v);
        }
        i = (u8) (i + 1);
    }
}
