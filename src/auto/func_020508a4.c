/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_02143cc0[];
s16 func_0201df30(s32, s32);
void func_02050058(u8 *);
void func_020559cc(u8 *, u8);
s32 func_020ad9a8(void);

void func_020508a4(u8 *arg0) {
    s32 mode;

    arg0[0x91] = 4;
    if (func_020ad9a8() != 0) {
        mode = 0x10;
    } else {
        mode = 0xF;
    }
    func_020559cc(arg0, mode);
    arg0[0xA2]              = 0;
    arg0[0xA3]              = 0;
    arg0[0x98]              = 0;
    *(s16 *) (arg0 + 0x184) = 0;
    *(s16 *) (arg0 + 0xA8)  = 0;
    *(s16 *) (arg0 + 0x186) = 2;
    *(s16 *) (arg0 + 0x18C) = 1;
    *(s16 *) (arg0 + 0x18E) = *(s16 *) (arg0 + 0x44);
    *(s16 *) (arg0 + 0x44)  = func_0201df30(*(s32 *) (data_02143cc0 + 0xF74), *(s32 *) (data_02143cc0 + 0xF7C));
    func_02050058(arg0);
}
