/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02011178(void *);                      /* extern */
M2C_UNK func_020f4ca4(M2C_UNK, s32, s32, M2C_UNK);  /* extern */
extern M2C_UNK data_0211bb10;
extern void *data_0213ad2c;

void func_02012d60(void *arg0, void *arg1) {
    if (M2C_FIELD(data_0213ad2c, u8 *, 8) == 0) {
        M2C_FIELD(arg0, s8 *, 5)     = 0;
        M2C_FIELD(arg1, u8 *, 0xE4)  = 0x58U;
        M2C_FIELD(arg1, s32 *, 0)    = 0x2A8000;
        M2C_FIELD(arg1, s32 *, 4)    = 0x1B1000;
        M2C_FIELD(arg1, s32 *, 8)    = 0;
        M2C_FIELD(arg1, s16 *, 0xC)  = 0;
        M2C_FIELD(arg1, s16 *, 0xE)  = 0;
        M2C_FIELD(arg1, s16 *, 0x10) = -0x1E00;
        M2C_FIELD(arg1, s16 *, 0x12) = 0x199A;
        M2C_FIELD(arg1, s16 *, 0x14) = 0x599;
        M2C_FIELD(arg1, s16 *, 0x16) = 0;
    } else {
        M2C_FIELD(arg0, s8 *, 5)     = 2;
        M2C_FIELD(arg1, u8 *, 0xE4)  = (u8) * ((u8 *) ((s8 *) &data_0211bb10 + (M2C_FIELD(data_0213ad2c, u8 *, 0xA) - 0x15)));
        M2C_FIELD(arg1, s32 *, 0)    = 0x1F5000;
        M2C_FIELD(arg1, s32 *, 4)    = 0x1FD000;
        M2C_FIELD(arg1, s32 *, 8)    = 0;
        M2C_FIELD(arg1, s16 *, 0xC)  = 0;
        M2C_FIELD(arg1, s16 *, 0xE)  = -0x8000;
        M2C_FIELD(arg1, s16 *, 0x10) = 0xFFFFDA60;
        M2C_FIELD(arg1, s16 *, 0x12) = 0x1666;
        M2C_FIELD(arg1, s16 *, 0x14) = 0x599;
        M2C_FIELD(arg1, s16 *, 0x16) = 0;
        func_020f4ca4(0, 0xFFFFF224, 0xFFFFF802, 0);
    }
    func_02011178(arg1);
    M2C_FIELD(arg1, s8 *, 0xEB) = 1;
}
