/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020038b8();                   /* extern */
M2C_UNK func_02003a0c();                     /* extern */
extern M2C_UNK data_02124b78;
extern M2C_UNK data_02124c48;
extern M2C_UNK data_02124cf4;
extern M2C_UNK data_0213b890;

void func_020befec(void) {
    u8 temp_r4;

    func_020038b8(&data_02124c48);
    temp_r4 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x13);
    func_020038b8(*((M2C_UNK *) ((s8 *) &data_02124cf4 + (temp_r4 * 0xC))));
    if (temp_r4 == 0xB) {
        func_02003a0c(1);
        func_020038b8(&data_02124b78);
    }
}
