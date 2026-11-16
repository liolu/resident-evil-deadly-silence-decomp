/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void func_02109bcc(void *);
extern void func_02109b60(void *);

s32 func_0200e800(s32 arg0) {
    u8 buf[32];
    s32 r4;

    func_02109bcc(buf);
    *(volatile u16 *) 0x040002B0 = 0;
    *(volatile s32 *) 0x040002B8 = arg0;
    while (*(volatile u16 *) 0x040002B0 & 0x8000) {
    }
    while (*(volatile u16 *) 0x040002B0 & 0x8000) {
    }
    r4 = *(volatile s32 *) 0x040002B4;
    func_02109b60(buf);
    return r4;
}
