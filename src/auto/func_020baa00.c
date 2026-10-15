/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020a2198(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;
extern M2C_UNK data_027e0028;

void func_020baa00(s32 arg0) {
    M2C_FIELD(&data_027e0028, s16 *, 2) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 0) = (s16) arg0;
    func_020a2198((s32) M2C_FIELD(data_027e000c, s16 *, 0x44), (s32) &data_027e0028, (s32) &data_027e0028);
    M2C_FIELD(data_027e000c, s32 *, 0x30) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x30) + M2C_FIELD(&data_027e0028, s16 *, 0));
    M2C_FIELD(data_027e000c, s32 *, 0x38) =
        (s32) (M2C_FIELD(data_027e000c, s32 *, 0x38) + M2C_FIELD(&data_027e0028, s16 *, 4));
}
