/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0201893c(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
extern u16 data_0213ad98;

void func_020194dc(void *arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(arg0, u8 *, 0x93) = (u8) (temp_r0 + 1);
            M2C_FIELD(arg0, s8 *, 0xA2) = 0;
            M2C_FIELD(arg0, s8 *, 0xA3) = 0;
            M2C_FIELD(arg0, s8 *, 0xA1) = 0xD;
            func_0205597c(0xF);
            M2C_FIELD(arg0, s8 *, 0xA2)                           = 0x19;
            *M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 **, 0x10) = 0x19000;
        /* fallthrough */
        case 1:
            if (func_0201893c(arg0, 0, 0x400) != 0) {
                M2C_FIELD(arg0, s8 *, 0x90) = 1;
                M2C_FIELD(arg0, s8 *, 0x91) = 1;
                M2C_FIELD(arg0, s8 *, 0x92) = 3;
                M2C_FIELD(arg0, u8 *, 0x93) = 0U;
                M2C_FIELD(arg0, s8 *, 0xA)  = 0;
                if (data_0213ad98 == 0x504) {
                    M2C_FIELD(arg0, s8 *, 0xA) = 4;
                }
                M2C_FIELD(arg0, s8 *, 0x96) = 0;
            }
            return;
    }
}
