/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_021261d0[];
extern M2C_UNK data_0213b890;

void func_020cf89c(void) {
    s32 *temp_r1;
    s32 *temp_r2;

    if (M2C_FIELD(&data_0213b890, u8 *, 0x21) != 3) {
        temp_r2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xD8), s32 **, 0x10);
        *temp_r2 += 0x1000;
        temp_r1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xD8), s32 **, 0x10);
        if (*temp_r1 == 0x34000) {
            *temp_r1 = 0;
        }
    }
    data_021261d0[M2C_FIELD(&data_0213b890, u8 *, 0x21)]();
}
