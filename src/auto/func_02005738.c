/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_02137264;
void func_02005648(void);
void func_02005164(u8);
void func_020053f4(u8 *, s8);
void func_020053c0(u8 *);

void func_02005738(void) {
    s32 mode;

    if (data_02137264 == NULL) {
        return;
    }
    mode = *(s32 *) (data_02137264 + 0xC);
    switch (mode) {
        case 0:
            break;
        case 1:
            func_02005648();
            break;
        case 3:
            return;
        default:
            return;
    }
    func_02005164(data_02137264[0x15]);
    func_020053f4(data_02137264 + 0x1A, *(s8 *) (data_02137264 + 0x14));
    func_020053c0(data_02137264 + 0x2AA);
}
