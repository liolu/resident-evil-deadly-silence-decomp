/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 func_020700d8(s32 kind, s32 idx);
extern u32 data_0214852c[];
extern u32 data_021485f4[];

void func_02017d74(s32 arg0) {
    u8 *p;
    s32 r;

    if (data_0214852c[arg0] == 0) {
        r = func_020700d8(2, arg0);
        if (r != 0) {
            data_0214852c[arg0] = r;
            p                   = (u8 *) data_0214852c[arg0];
            data_021485f4[arg0] = r + p[2] * 4 + p[0] * 4 + 8;
        }
    }
}
