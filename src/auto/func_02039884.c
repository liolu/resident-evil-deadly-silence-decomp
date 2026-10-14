/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02034f70(void);

extern void *data_027e000c;
extern s32 data_027e0020;

void func_02039884(void) {
    s16 temp_r1;
    void *temp_r1_2;
    void *temp_r3;

    if (M2C_FIELD(data_027e000c, u8 *, 0x91) == 0) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 8;
        M2C_FIELD(data_027e000c, u8 *, 0x91) = 1U;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 0xE;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        temp_r3 = M2C_FIELD(data_027e000c, void **, 0x9C);
        M2C_FIELD(temp_r3, s16 *, 0x40) = (s16) (M2C_FIELD(temp_r3, s16 *, 0x40) - 1);
        temp_r1 = M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s16 *, 0x40);
        data_027e0020 = (s32) temp_r1;
        if (temp_r1 == 1) {
            temp_r1_2 = M2C_FIELD(data_027e000c, void **, 0x9C);
            M2C_FIELD(temp_r1_2, s16 *, 0x40) = (s16) (M2C_FIELD(temp_r1_2, s16 *, 0x40) - 1);
        }
        if (!(M2C_FIELD(data_027e000c, u8 *, 0xA) & 1)) {
            M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s16 *, 0x94) = -1;
            M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s8 *, 0x90) = 3;
            M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s8 *, 0x91) = 0;
            M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s8 *, 0x92) = 0;
            M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0x9C), s8 *, 0x93) = 0;
        }
    }
    func_02034f70();
}
