/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020559cc(M2C_UNK, M2C_UNK);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02052660(void) {
    M2C_FIELD(data_027e000c, s32 *, 0x188) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x188) + M2C_FIELD(data_027e000c, s32 *, 0x17C));
    M2C_FIELD(data_027e000c, s32 *, 0x190) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x190) + M2C_FIELD(data_027e000c, s32 *, 0x184));
    M2C_FIELD(data_027e000c, s32 *, 0x30) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x188) >> 0x10);
    M2C_FIELD(data_027e000c, s32 *, 0x38) = (s32) ((s32) M2C_FIELD(data_027e000c, s32 *, 0x190) >> 0x10);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA8) - 1);
    if (M2C_FIELD(data_027e000c, s16 *, 0xA8) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        func_020559cc((s32) data_027e000c, 6);
    }
    func_02075738(1, 0x200);
}
