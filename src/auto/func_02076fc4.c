/* compiler: 1.2/sp3 -O2,p */
#include "m2c.h"

extern M2C_UNK data_021406b4;
extern M2C_UNK data_02141cbc;

u32 func_02076fc4(void) {
    u8 *p;
    u8 *end;

    end = (u8 *) &data_02141cbc;
    p   = (u8 *) &data_021406b4;
    goto check;
loop:
    if (*(s32 *) (p + 4) == 0) {
        *(s32 *) (p + 0x74) = 0;
        return (u32) p;
    }
    p += 0x78;
check:
    if ((u32) p < (u32) end) {
        goto loop;
    }
    return 0;
}
