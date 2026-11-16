/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);
extern Handler data_0211ced4[];
void func_02050a30(void *, s32);

void func_02050a50(void *arg0) {
    s32 temp_r1;
    u8 temp_r2;

    temp_r2 = M2C_FIELD(arg0, u8 *, 0xA);
    temp_r1 = temp_r2 & 0x80;
    if (temp_r1 != 0) {
        func_02050a30(arg0, temp_r1);
        M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 8);
    } else {
        data_0211ced4[temp_r2 & 0xF](arg0);
    }
    M2C_FIELD(arg0, s8 *, 0x92) = 0;
    M2C_FIELD(arg0, s8 *, 0x93) = 0;
}
