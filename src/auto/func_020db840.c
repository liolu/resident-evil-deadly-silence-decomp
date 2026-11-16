/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Cb)(void *, s32, s32);

typedef struct {
    u8 pad0[14];
    s8 f14;
    u8 pad1[129];
    s32 f144;
    s32 f148;
    u8 pad2[68];
    s32 f220;
    s32 pad3;
    Cb f228;
    void *f232;
} Ctx;

void func_020db840(Ctx *arg0) {
    s32 diff;
    s32 prod;
    s32 cnt;
    s32 wr;
    s32 rd;

    rd   = arg0->f220;
    wr   = arg0->f148;
    cnt  = arg0->f144;
    diff = wr - rd;
    if (diff < 0) {
        diff = (0x7FFFFFFF - rd) + wr;
    }
    prod = arg0->f14 * (cnt << 1);
    arg0->f228(arg0->f232, diff, prod);
    arg0->f220 = arg0->f148;
}
