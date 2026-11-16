/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Fn)(void);
extern Fn data_0211cf80[];
extern void *data_027e000c;

void func_02051ecc(void) {
    u8 temp_r2;

    temp_r2 = M2C_FIELD(data_027e000c, u8 *, 0xA);
    if ((temp_r2 & 0x80) || (temp_r2 & 0x20)) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
        return;
    }
    if (temp_r2 & 0x40) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
        M2C_FIELD(data_027e000c, u8 *, 0xA)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) & ~0x40);
    }
    data_0211cf80[M2C_FIELD(data_027e000c, u8 *, 0xA) & 0xF]();
}
