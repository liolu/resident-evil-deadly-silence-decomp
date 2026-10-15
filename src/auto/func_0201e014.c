/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_01ffd504(M2C_UNK);
void func_0201923c(M2C_UNK);
void func_020b8138(M2C_UNK, M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_0201e014(void) {
    void *temp_r2;

    M2C_FIELD(data_027e000c, s8 *, 0xA1)  = 0xA;
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = 0x14;
    temp_r2                               = data_027e000c + 0x17C;
    M2C_FIELD(temp_r2, s16 *, 6)          = (s16) (M2C_FIELD(temp_r2, s16 *, 6) | 1);
    if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0x12) {
        func_020b8138(0x1E, (s32) (data_027e000c + 0x30), 0);
    }
    if ((u32) M2C_FIELD(data_027e000c, u8 *, 0xA2) < 5U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) + 0x5A);
    }
    func_0201923c((s32) data_027e000c);
    func_01ffd504(0x800);
}
