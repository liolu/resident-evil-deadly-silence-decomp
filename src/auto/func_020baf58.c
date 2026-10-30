/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s16 func_0201df30(s32, s32);                        /* extern */
M2C_UNK func_020552f0(M2C_UNK);                     /* extern */
M2C_UNK func_020ba630(s16, s16);                    /* extern */
M2C_UNK func_020ba93c();                            /* extern */
M2C_UNK func_020baa00(s16);                         /* extern */
M2C_UNK func_020baa74(M2C_UNK);                     /* extern */
M2C_UNK func_020bb6ec(s32);                         /* extern */
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;

void func_020baf58(void) {
    void *temp_ip;
    void *temp_r3;

    M2C_FIELD(data_027e000c, s16 *, 0x186) =
        func_0201df30(M2C_FIELD(&data_02143cc0, s32 *, 0xF74), M2C_FIELD(&data_02143cc0, s32 *, 0xF7C));
    if ((u32) ((M2C_FIELD(data_027e000c, s16 *, 0x186) + 0x200) - M2C_FIELD(data_027e000c, s16 *, 0x44)) <= 0x400U) {
        if (M2C_FIELD(data_027e000c, u8 *, 0xA1) != 3) {
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 3U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
            func_020bb6ec(0x8003);
        }
        func_020baa74(0x30);
        func_020baa00(-0x3C);
        func_020ba630((s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74), (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C));
        return;
    }
    if (M2C_FIELD(data_027e000c, u8 *, 0xA1) != 7) {
        M2C_FIELD(data_027e000c, u8 *, 0xA1) = 7U;
        M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
        func_020bb6ec(0x8002);
    }
    temp_ip                        = data_027e000c + 0x17C;
    M2C_FIELD(temp_ip, s16 *, 0xA) = (s16) (M2C_FIELD(temp_ip, s16 *, 0xA) + 0x800);
    temp_r3                        = data_027e000c + 0x17C;
    M2C_FIELD(temp_r3, s16 *, 0xA) = (s16) (M2C_FIELD(temp_r3, s16 *, 0xA) & 0xFFF);
    func_020baa74(0x30);
    func_020552f0(0x5D);
    func_020baa00(M2C_FIELD(data_027e000c, s16 *, 0xA6));
    func_020ba93c();
}
