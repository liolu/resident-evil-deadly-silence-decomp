/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020823b4(void *arg0, u8 arg1, s32 arg2, s32 arg3);

void func_02082ee0(u8 *arg0) {
    u8 *base;
    u8 *tbl;
    u8 *e;
    s32 idx;
    s8 v;

    base = *(u8 **) arg0;
    tbl  = *(u8 **) (arg0 + 0x24);
    idx  = base[0x93] * 0xC;
    e    = tbl + idx;
    func_020823b4(arg0, tbl[idx], 0, 0);
    *(u16 *) (arg0 + 0x98) = *(u16 *) (e + 4);
    if (*(s8 *) (e + 3) != 0) {
        v = *(s8 *) (arg0 + 0x15);
    } else {
        v = *(s8 *) (arg0 + 0x14);
    }
    *(s16 *) (arg0 + 0x9A) = v;
    arg0[0x9C]             = e[8];
    arg0[0x9E]             = e[0xA];
    arg0[0x9F]             = e[0xB];
    base                   = *(u8 **) arg0;
    base[0x92]             = base[0x92] + 1;
}
