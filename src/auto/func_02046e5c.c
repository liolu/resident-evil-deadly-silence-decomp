/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0211cbd0;
extern M2C_UNK data_0213ad48;
extern void *data_027e000c;

void func_02046e5c(void) {
    void (**tbl)(void);

    if (M2C_FIELD(data_027e000c, u8 *, 0x91) == 0) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 3;
        M2C_FIELD(data_027e000c, u8 *, 0x91) = 1U;
        M2C_FIELD(data_027e000c, u8 *, 0x92) = 0U;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        if ((M2C_FIELD(&data_0213ad48, u8 *, 4) == 0) && (M2C_FIELD(data_027e000c, u8 *, 9) == 0x10)) {
            M2C_FIELD(data_027e000c, u8 *, 0x92) = 1U;
        }
    }
    tbl = (void (**)(void)) &data_0211cbd0;
    tbl[M2C_FIELD(data_027e000c, u8 *, 0x92)]();
}
