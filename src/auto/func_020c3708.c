/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a04f0(M2C_UNK *);                   /* extern */
M2C_UNK func_020c36f4();                            /* extern */
extern M2C_UNK data_0211de34;
extern M2C_UNK data_0213bae8;
extern M2C_UNK data_02143cc0;

void func_020c3708(s32 arg0, s8 arg1) {
    func_020c36f4();
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = arg1;
    if (*((u16 *) ((s8 *) &data_0211de34 + (arg0 * 8))) != 0) {
        func_020a04f0(&data_0213bae8);
    }
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
}
