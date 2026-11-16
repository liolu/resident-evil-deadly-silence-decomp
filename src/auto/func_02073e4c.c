/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0211db5c;
extern u8 data_0214bcc0;

u8 func_02073e4c(s32 arg0, s32 arg1) {
    u32 r2;
    u16 *tbl;
    u32 r4;
    u8 *e;

    r2  = 0;
    tbl = *(u16 **) (*(u8 **) ((u8 *) &data_0214bcc0 + 0x7ac) + 0x54);
    r4  = tbl[0] & 0xff;
    e   = (u8 *) tbl + 2;
    goto cond;
body:
    if ((u32) (arg0 - *(u16 *) (e + 0)) < *(u16 *) (e + 4)) {
        if ((u32) (arg1 - *(u16 *) (e + 2)) < *(u16 *) (e + 6)) {
            return ((u32 *) &data_0211db5c)[*(u16 *) (e + 8) & 0xff] & 0xff;
        }
    }
    r2 = r2 + 1;
    e  = e + 10;
    r2 = r2 & 0xff;
cond:
    if (r2 < r4) {
        goto body;
    }
    return 0;
}
