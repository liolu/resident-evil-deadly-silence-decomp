/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02092bac(void);
void func_0206fcf8(s32, s32, s32, s32);
void func_02056204(s32, s32);
extern u16 data_0213ad84;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ad3c;

void func_0205603c(void) {
    u16 temp_r1;

    if (data_0213ad84 == 0) {
        temp_r1 = M2C_FIELD(&data_0213b890, u16 *, 0x26);
        if (temp_r1 == 0) {
            if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x10) {
                func_02092bac();
                func_0206fcf8(0, 2, 1, 0x80);
                func_02056204(2, 0);
            }
        } else {
            M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (temp_r1 - 1);
        }
    }
}
