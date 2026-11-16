/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0211afbc;
extern u8 data_0211b028;
extern u8 data_0213b2b4;

typedef void (*Fn48)(s32, s32, s32);

typedef struct {
    u16 *p;
    Fn48 fn;
} Ent48;

s32 func_021046d4(s32 a, s32 b);
s32 func_021060e8(s32 a, s32 b, s32 c);

void func_02003a0c(s32 arg0) {
    Ent48 *base;
    volatile u16 sp0;
    volatile s32 sp4;
    Fn48 fn;
    s32 r5;

    base = (Ent48 *) &data_0211b028;
    sp0  = *base[arg0].p;
    fn   = base[arg0].fn;
    r5   = (&data_0211afbc)[((u32) sp0 << 16) >> 30] << 11;
    sp4  = 0;
    func_021060e8(sp4, *(s32 *) ((u8 *) &data_0213b2b4 + 0xc8), r5);
    func_021046d4(*(s32 *) ((u8 *) &data_0213b2b4 + 0xc8), r5);
    fn(*(s32 *) ((u8 *) &data_0213b2b4 + 0xc8), 0, r5);
}
