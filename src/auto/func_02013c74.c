/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 func_0200ea0c(void *, s32, u8);                  /* extern */
M2C_UNK func_02013a00(void *);                      /* extern */
M2C_UNK func_02013b1c(void *);                      /* extern */
M2C_UNK func_02013c48();                            /* extern */
M2C_UNK func_02014c0c(void *);                      /* extern */
extern M2C_UNK data_0214bcc0;

void func_02013c74(void *arg0) {
    s16 temp_r0;
    s16 temp_r0_2;
    u16 temp_r0_3;

    M2C_FIELD(arg0, s32 *, 0x20) = (s32) (M2C_FIELD(arg0, s32 *, 0x20) + M2C_FIELD(arg0, s16 *, 0x32));
    M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + M2C_FIELD(arg0, s16 *, 0x36));
    temp_r0                      = M2C_FIELD(arg0, s16 *, 0x32);
    if ((s32) temp_r0 >= 0) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) (temp_r0 - 4);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x32) < 0) {
            M2C_FIELD(arg0, s16 *, 0x32) = 0;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) (temp_r0 + 4);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x32) > 0) {
            M2C_FIELD(arg0, s16 *, 0x32) = 0;
        }
    }
    temp_r0_2 = M2C_FIELD(arg0, s16 *, 0x36);
    if ((s32) temp_r0_2 >= 0) {
        M2C_FIELD(arg0, s16 *, 0x36) = (s16) (temp_r0_2 - 4);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x36) < 0) {
            M2C_FIELD(arg0, s16 *, 0x36) = 0;
        }
    } else {
        M2C_FIELD(arg0, s16 *, 0x36) = (s16) (temp_r0_2 + 4);
        if ((s32) M2C_FIELD(arg0, s16 *, 0x36) > 0) {
            M2C_FIELD(arg0, s16 *, 0x36) = 0;
        }
    }
    func_02013a00(arg0);
    M2C_FIELD(arg0, u16 *, 0x1C) = (u16) (M2C_FIELD(arg0, u16 *, 0x1C) + 1);
    temp_r0_3                    = M2C_FIELD(arg0, u16 *, 0x1C);
    if (temp_r0_3 == 0xF) {
        func_02013b1c(arg0);
        func_02013c48();
        goto block_16;
    }
    if (temp_r0_3 == 0x19) {
        func_02013b1c(arg0);
        func_02013c48();
        func_02014c0c(arg0);
        return;
    }
block_16:
    M2C_FIELD(arg0, u8 *, 0x13) =
        func_0200ea0c(arg0 + 0x20, M2C_FIELD(&data_0214bcc0, s32 *, 0x7B0), M2C_FIELD(arg0, u8 *, 0x13));
}
