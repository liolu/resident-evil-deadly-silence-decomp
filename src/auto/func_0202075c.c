/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0201ec54(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020abd88(M2C_UNK);                     /* extern */
M2C_UNK func_020ad70c(M2C_UNK);                     /* extern */
M2C_UNK func_020b8110(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020b8210(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_020d9854(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;
extern M2C_UNK data_02144c34;

void func_0202075c(M2C_UNK *arg0) {
    u8 temp_r5;

    if ((u32) M2C_FIELD(arg0, u8 *, 0xA2) < 0x14U) {
        func_020d9854(&data_02144c04);
    }
    if (func_0209109c(0, 0x1000, 7) != 0) {
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
    }
    temp_r5 = M2C_FIELD(arg0, u8 *, 0xA2);
    if (temp_r5 == 0x8C) {
        M2C_FIELD(&data_02143cc0, s8 *, 0xF43) = 1;
        func_020ad70c(-1);
    }
    if (temp_r5 == 0x2A) {
        func_020b8110(0x47, 0);
    }
    if (temp_r5 == 0x60) {
        func_020b8110(0x4B, 0);
        func_020abd88(3);
    }
    if (temp_r5 == 0x5B) {
        M2C_FIELD(arg0, s16 *, 0x192) = 8;
        func_020b8210(3, 3, &data_02144c34, 0);
    }
    if (M2C_FIELD(arg0, s16 *, 0x192) != 0) {
        func_0201ec54(&data_02144c04, 1, 3);
        func_0201ec54(arg0, 0xC, 0);
    }
}
