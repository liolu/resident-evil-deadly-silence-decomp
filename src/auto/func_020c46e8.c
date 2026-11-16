/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);

extern u8 data_0213b8e0;
extern u8 data_0213b89c;
extern u8 data_0213fae8;

void func_02003560(s32, s32);
void func_020c3b9c(void *);
void func_021061d8(void *, s32, s32);
void func_02106070(s32, void *, s32);

void func_020c46e8(s32 arg0, s32 arg1) {
    volatile u16 sp0;
    Fn fp;
    u8 *base;

    base = (u8 *) &data_0213b8e0;
    fp   = *(Fn *) (base + 0x2C);
    if (fp != NULL) {
        fp();
    }
    func_020c3b9c(base);
    func_021061d8(base, 0, 0x34);
    *(s32 *) (base + 0x24) = arg0;
    *(s32 *) (base + 0x10) = arg1;
    func_021061d8(&data_0213b89c, 0, 0xA);
    sp0 = 0;
    func_02106070(sp0, &data_0213fae8, 0x800);
    func_02003560(4, 0);
}
