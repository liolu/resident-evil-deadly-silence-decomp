#include "m2c.h"

M2C_UNK func_020b39e4(M2C_UNK *, u8);               /* extern */
extern M2C_UNK data_0211e76c;
extern M2C_UNK data_0213be84;

void func_02078958(s32 arg0) {
    func_020b39e4(&data_0213be84, *((u8 *) ((s8 *) &data_0211e76c + (arg0 & 0xF))));
}
