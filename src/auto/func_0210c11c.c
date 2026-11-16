/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_02103b00(void *);
s32 func_021054ac();
M2C_UNK func_021054c0(s32);
extern M2C_UNK data_0215a960;

s32 func_0210c11c(void) {
    u8 *temp_r6;
    s32 temp_r5;
    u8 *temp_r4;

    temp_r6 = (u8 *) &data_0215a960;
    temp_r5 = func_021054ac();
    if (M2C_FIELD(temp_r6, s32 *, 0xE0) & 4) {
        temp_r4 = temp_r6 + 0xDC;
        do {
            func_02103b00(temp_r4);
        } while (M2C_FIELD(temp_r6, s32 *, 0xE0) & 4);
    }
    func_021054c0(temp_r5);
    if (*M2C_FIELD(temp_r6, s32 **, 0) == 0) {
        return 1;
    }
    return 0;
}
