/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020adad0(M2C_UNK);

extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

void func_020a7eb0(s32 arg0) {
    s32 *temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x90) != 0) {
        if (M2C_FIELD(&data_0213daa8, u8 *, 0x23C) != 0) {
            M2C_FIELD(arg0, u8 *, 0x90) = (u8) M2C_FIELD(&data_0213daa8, u8 *, 0x23C);
            M2C_FIELD(arg0, u8 *, 0x91) = (u8) M2C_FIELD(&data_0213daa8, u8 *, 0x23D);
            M2C_FIELD(arg0, u8 *, 0x92) = (u8) M2C_FIELD(&data_0213daa8, u8 *, 0x23E);
            M2C_FIELD(arg0, u8 *, 0x93) = (u8) M2C_FIELD(&data_0213daa8, u8 *, 0x23F);
            M2C_FIELD(&data_0213daa8, u8 *, 0x23C) = 0U;
            if (M2C_FIELD(&data_0213daa8, u8 *, 0x245) != 0) {
                M2C_FIELD(&data_0213daa8, u8 *, 0x245) = 0U;
                M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 0;
            }
        }
        if (M2C_FIELD(&data_0213daa8, s32 *, 0x240) != 0) {
            func_020adad0((s32) (u16) M2C_FIELD(&data_0213daa8, s32 *, 0x240));
            *M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 **, 0x10) = M2C_FIELD(arg0, u8 *, 0xA2) << 0xC;
            M2C_FIELD(&data_0213daa8, s32 *, 0x240) = 0;
            if (M2C_FIELD(arg0, u16 *, 0xEC) & 1) {
                temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 **, 0x10);
                M2C_FIELD(temp_r1, s32 *, 0) = M2C_FIELD(M2C_FIELD(temp_r1, void **, 8), u16 *, 4) << 0xC;
            }
        }
    }
    M2C_FIELD(arg0, u8 *, 0xB) = (u8) (M2C_FIELD(arg0, u8 *, 0xB) | M2C_FIELD(&data_0213daa8, u8 *, 0x244));
    M2C_FIELD(&data_0213daa8, u8 *, 0x244) = 0U;
}
