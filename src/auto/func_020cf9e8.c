/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK func_0206fcf8(s32, s32, s32, s32);
extern M2C_UNK func_020c4798(s32);
extern u8 data_0213ad84;
extern u8 data_0213ad98[];
extern u8 data_0213b890[];

void func_020cf9e8(void) {
    if (data_0213ad84 != 0) {
        return;
    }
    if (data_0213ad98[5] & 0x80) {
        return;
    }
    if (data_0213ad98[5] != 0) {
        func_020c4798(3);
        return;
    }
    data_0213b890[0x21] = 1;
    func_0206fcf8(0, 1, 1, 0x100);
}
