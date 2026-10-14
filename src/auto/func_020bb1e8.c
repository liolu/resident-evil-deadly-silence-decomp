/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020552f0(M2C_UNK);
void func_020ba6f4(M2C_UNK);
void func_020baa00(M2C_UNK);
void func_020baa74(M2C_UNK);
void func_020bac80(void);
void func_020bb6ec(M2C_UNK);

extern void *data_027e000c;

void func_020bb1e8(void) {
    func_020bac80();
    if (M2C_FIELD(data_027e000c, u8 *, 0x93) == 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
        if (M2C_FIELD(data_027e000c, u8 *, 0xA1) != 7) {
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 7U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
            func_020bb6ec(0x8002);
        }
    }
    if ((u32) ((M2C_FIELD(data_027e000c, s16 *, 0x186) + 0x180) - M2C_FIELD(data_027e000c, s16 *, 0x44)) <= 0x300U) {
        func_020baa74(0x30);
        func_020552f0(0x5D);
        func_020baa00((s32) M2C_FIELD(data_027e000c, s16 *, 0xA6));
    } else {
        func_020baa74(0x28);
    }
    func_020ba6f4(0);
}
