/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02016b08(void *);
extern u8 data_021489a3[];
extern s32 data_027e0018;

void func_02017478(void *arg0) {
    s32 temp_r2;

    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) >= 0) {
        M2C_FIELD(arg0, s8 *, 0)     = 0x2F;
        M2C_FIELD(arg0, s8 *, 1)     = 0;
        M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (0 - (M2C_FIELD(arg0, s16 *, 0x2A) + M2C_FIELD(arg0, s32 *, 0x48)));
        func_02016b08(arg0);
        temp_r2                = data_027e0018 * 0xBC;
        data_021489a3[temp_r2] = data_021489a3[temp_r2] + (M2C_FIELD(arg0, u8 *, 3) - 3);
    }
}
