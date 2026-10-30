/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

extern M2C_UNK data_027e01ac;
extern M2C_UNK data_027e01ec;

void func_0209f464(void *arg0) {
    if (((u32) (M2C_FIELD(arg0, u8 *, 0x105A) << 0x1F) >> 0x1F) == 0) {
        M2C_FIELD(arg0, void **, 0x1054) =
            (void *) ((M2C_UNK *) ((s8 *) &data_027e01ac + (M2C_FIELD(arg0, u8 *, 0x105B) * 0x10)));
    } else {
        M2C_FIELD(arg0, void **, 0x1054) =
            (void *) ((M2C_UNK *) ((s8 *) &data_027e01ec + (M2C_FIELD(arg0, u8 *, 0x105B) * 0x10)));
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1054), s32 *, 0xC) = (s32) M2C_FIELD(arg0, s32 *, 0x1000);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1054), s16 *, 6)   = 0x600;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x1054), s8 *, 8)    = 1;
}
