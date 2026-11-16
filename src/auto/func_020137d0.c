/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_021060a4(s32, s8 *, M2C_UNK);
M2C_UNK func_0210a118(M2C_UNK *);
s32 func_0210a260(M2C_UNK *);
M2C_UNK func_0210a30c();
extern s8 data_0213ae4c;
extern M2C_UNK data_0213ae90;

void func_020137d0(void) {
    volatile s32 sp0;

    func_0210a30c();
    sp0 = 0;
    func_021060a4(sp0, &data_0213ae4c, 0x4C);
    data_0213ae4c = 5;
    if (func_0210a260(&data_0213ae90) != 0) {
        func_0210a118(&data_0213ae90);
    }
}
