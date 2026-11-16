/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 pad0;
    u8 kind;
    s16 f2;
    s16 f4;
    s16 f6;
    s8 f8;
    s8 f9;
} Buf48;

void func_02056d04(s32 a, void *b);

s32 func_02059220(u8 *arg0) {
    Buf48 buf;

    buf.kind = (*(u8 **) (arg0 + 8))[1];
    if (*(volatile u8 *) &buf.kind == 0x10) {
        func_02056d04(*(s32 *) (arg0 + 4), &buf);
        return 2;
    }
    buf.f2 = *(s16 *) (*(u8 **) (arg0 + 8) + 2);
    buf.f4 = *(s16 *) (*(u8 **) (arg0 + 8) + 4);
    buf.f6 = *(s16 *) (*(u8 **) (arg0 + 8) + 6);
    buf.f8 = *(s8 *) (*(u8 **) (arg0 + 8) + 8);
    buf.f9 = *(s8 *) (*(u8 **) (arg0 + 8) + 9);
    func_02056d04(*(s32 *) (arg0 + 4), &buf);
    return 0xA;
}
