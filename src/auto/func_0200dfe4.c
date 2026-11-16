/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_021372d8;
extern u8 *data_021372d0;
extern u8 *data_021372cc;
void func_021060e8(s32, s32, s32);

void func_0200dfe4(void) {
    volatile s32 sp0;
    u8 *p;

    p                               = (u8 *) (data_021372d8 + 0x3F40);
    data_021372d0                   = p;
    data_021372cc                   = p + 0x14;
    *(s32 *) (p + 4)                = 0;
    *(s32 *) data_021372d0          = *(s32 *) (data_021372d0 + 4);
    *(s32 *) (data_021372d0 + 0xC)  = 0;
    *(s32 *) (data_021372d0 + 0x10) = 1;
    *(s32 *) (data_021372d0 + 8)    = 0;
    sp0                             = 0;
    func_021060e8(sp0, (s32) data_021372cc, 0x400);
}
