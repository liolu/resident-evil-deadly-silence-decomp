/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020552f0(M2C_UNK);
void func_020ba630(M2C_UNK, M2C_UNK);
void func_020baa00(M2C_UNK);
void func_020baa74(M2C_UNK);
void func_020bac80(void);
void func_020bb6ec(M2C_UNK);

extern void *data_027e000c;

void func_020bb0bc(void) {
    func_020bac80();
    if ((u32) ((M2C_FIELD(data_027e000c, s16 *, 0x186) + 0x180) - M2C_FIELD(data_027e000c, s16 *, 0x44)) <= 0x300U) {
        if (M2C_FIELD(data_027e000c, u8 *, 0xA1) != 8) {
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 8U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
            func_020bb6ec(0x8005);
        }
        func_020baa74(0x60);
        func_020baa00(0xD2);
    } else {
        if (M2C_FIELD(data_027e000c, u8 *, 0xA1) != 7) {
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 7U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
            func_020bb6ec(0x8002);
        }
        func_020baa74(0x30);
        if ((u32) ((M2C_FIELD(data_027e000c, s16 *, 0x186) + 0x200) - M2C_FIELD(data_027e000c, s16 *, 0x44)) <= 0x400U) {
            func_020552f0(0x5D);
            func_020baa00((s32) M2C_FIELD(data_027e000c, s16 *, 0xA6));
        }
    }
    func_020ba630((s32) M2C_FIELD(data_027e000c, s16 *, 0x176), (s32) M2C_FIELD(data_027e000c, s16 *, 0x178));
}
