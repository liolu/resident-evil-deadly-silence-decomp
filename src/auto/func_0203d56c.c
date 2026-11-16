/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211ca24[];
s32 func_020d9650(void);
extern void *data_027e000c;
extern s32 data_027e0024;

void func_0203d56c(void) {
    s32 temp_r0;

    temp_r0       = func_020d9650();
    data_027e0024 = temp_r0;
    if ((temp_r0 >> 1) == 0) {
        M2C_FIELD(data_027e000c, s16 *, 0x17E) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x17E) & 0xFFFE);
        M2C_FIELD(data_027e000c, s16 *, 0x17E) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x17E) | (data_027e0024 & 1));
    }
    data_0211ca24[M2C_FIELD(data_027e000c, u8 *, 0x92)]();
}
