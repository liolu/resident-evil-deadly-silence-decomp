/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0208280c(void *);
void *func_02088580(void);
void func_02084fb4(void *, s32);

void func_020835ec(void *arg0) {
    void *temp_r2;
    void *temp_r4;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if ((M2C_FIELD(temp_r2, u8 *, 0x91) == 0xA) && (M2C_FIELD(temp_r2, u8 *, 0x92) != 0xFF)) {
        func_0208280c(arg0);
    } else {
        temp_r4                                           = func_02088580();
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0xB) = 0;
        func_02084fb4(arg0, 1);
        if (((u32) (M2C_FIELD(arg0, u8 *, 7) << 0x1C) >> 0x1F) != 0) {
            M2C_FIELD(temp_r4, u8 *, 0xEA) = (u8) ((M2C_FIELD(temp_r4, u8 *, 0xEA) & ~1) | 1);
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x90) = 3;
    }
}
