/* compiler: 1.2/sp3 -O2,p */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

extern M2C_UNK data_0212cab8;
extern s32 data_021402e8;
extern void **data_027e000c;

void func_02039d10(s32 arg0) {
    u8 *temp_r2;
    s32 temp_r3;
    s32 temp_ip;
    s32 temp_r1;

    temp_r2                      = M2C_FIELD(*data_027e000c, u8 **, 0x14);
    temp_ip                      = (temp_r2[1] * 0x58) + data_021402e8;
    temp_r3                      = arg0 * 0x58;
    temp_r2                      = (u8 *) (temp_ip + temp_r3);
    temp_r1                      = *(s32 *) (temp_ip + temp_r3);
    *(s32 *) (temp_ip + temp_r3) = temp_r1 & ~1;
    *(T12 *) (temp_r2 + 4)       = *(T12 *) &data_0212cab8;
}
