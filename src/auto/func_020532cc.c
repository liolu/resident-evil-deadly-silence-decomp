/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020182f0(M2C_UNK, M2C_UNK, M2C_UNK, void *, M2C_UNK *, s32); /* extern */
M2C_UNK func_020532a8(void *);                      /* extern */
M2C_UNK func_020a2fbc(void *);                      /* extern */
M2C_UNK func_020abd88(M2C_UNK);                     /* extern */
M2C_UNK func_020ad70c(M2C_UNK);                     /* extern */
M2C_UNK func_020ad71c(u8, M2C_UNK);                 /* extern */
M2C_UNK func_020ad960();                            /* extern */
s32 func_020d9c80(s16, s16, M2C_UNK, s16);          /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern s32 data_027e0018;
extern M2C_UNK data_027e0054;

void func_020532cc(void *arg0) {
    s32 temp_r5;

    if (func_020d9c80(M2C_FIELD(arg0, s16 *, 0xA6), M2C_FIELD(arg0, s16 *, 0x17C), -0x1E, M2C_FIELD(arg0, s16 *, 0x9A)) != 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 2;
    }
    temp_r5 = M2C_FIELD(arg0, s32 *, 0x34);
    func_020a2fbc(arg0);
    func_020532a8(arg0);
    M2C_FIELD(arg0, s32 *, 0x34) = temp_r5;
    if (((s32) data_027e0018 < 0x320) && (M2C_FIELD(arg0, s16 *, 0x180) == 0)) {
        func_020abd88(0);
        M2C_FIELD(arg0, s16 *, 0x44)        = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x400);
        M2C_FIELD(arg0, s16 *, 0xA6)        = (s16) (M2C_FIELD(arg0, s16 *, 0xA6) - 0x3C);
        M2C_FIELD(arg0, s16 *, 0x180)       = 1;
        M2C_FIELD(&data_027e0054, s32 *, 0) = 0;
        M2C_FIELD(&data_027e0054, s32 *, 4) = 0;
        M2C_FIELD(&data_027e0054, s32 *, 8) = 0;
        func_020182f0(0, 0, 0, arg0 + 0x1C, &data_027e0054, 0);
        func_020ad71c(M2C_FIELD(arg0, u8 *, 9), 2);
        if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0) {
            func_020ad70c(1);
        }
        M2C_FIELD(&data_02143cc0, s8 *, 0xFD6) = 0x64;
        M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 1;
        func_020ad960();
    }
}
