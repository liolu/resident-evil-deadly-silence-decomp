/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef s32 (*Handler)(void);

void func_0206fcf8(s32, s32, s32, s32);
extern Handler data_0211d2e0[];
extern s16 data_0212d000;
extern s8 data_0213746c;
extern u8 data_0213ad84;
extern M2C_UNK data_0213daa8;

void func_02058744(void) {
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x80);
    if (data_0213ad84 == 0) {
        if (data_0211d2e0[data_0212d000]() != 0) {
            func_0206fcf8(0, 1, 0, 0x80);
        }
        data_0213746c = 2;
    }
}
