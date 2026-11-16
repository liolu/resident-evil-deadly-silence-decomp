/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_021060a4(s32, void *, M2C_UNK);        /* extern */
extern s32 data_02136924;
extern s32 data_02136928;
extern s32 data_0213692c;

void func_020f4658(void *arg0, s32 arg1) {
    volatile s32 sp0;

    sp0 = 0;
    func_021060a4(sp0, arg0, 0x54);
    M2C_FIELD(arg0, s32 *, 0xC)  = (s32) data_0213692c;
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) data_02136928;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) data_02136924;
    M2C_FIELD(arg0, s32 *, 4)    = arg1;
}
