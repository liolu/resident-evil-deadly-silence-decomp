/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200ef6c(s32, M2C_UNK *);              /* extern */
s32 func_020765d4(M2C_UNK, M2C_UNK *, s32);         /* extern */
M2C_UNK func_02076664(M2C_UNK *);                   /* extern */
s32 func_02088648();                                /* extern */
M2C_UNK func_0208875c(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
void *func_020f8758(s32);                           /* extern */
extern M2C_UNK data_0213ad28;
extern M2C_UNK data_0213ad29;
extern M2C_UNK data_0213ad2a;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bd4;

void func_020a0864(void) {
    s32 temp_r0;
    void *temp_r0_2;
    void *temp_r3;

    if ((M2C_FIELD(&data_02143cc0, s32 *, 0xF34) != 0) && (M2C_FIELD(&data_02143cc0, s32 *, 0xF38) != 0)) {
        if (func_02088648() != 0) {
            func_0208875c(&data_0213ad28, &data_0213ad29, &data_0213ad2a);
        } else {
            func_02076664(&data_0213ad28);
        }
        temp_r0 = func_020765d4(0, &data_0213ad28, M2C_FIELD(&data_02143cc0, s32 *, 0xF08));
        if (temp_r0 == 0) {
            M2C_FIELD(&data_02143cc0, s8 *, 0xF30) = 0;
            return;
        }
        func_0200ef6c(temp_r0, &data_02144bd4);
        temp_r0_2                               = func_020f8758(temp_r0);
        temp_r3                                 = temp_r0_2 + 0x3C + M2C_FIELD(temp_r0_2, u16 *, 0x42);
        M2C_FIELD(&data_02143cc0, s32 *, 0xF20) = (s32) M2C_FIELD(temp_r0_2, s32 *, 0x18);
        M2C_FIELD(&data_02143cc0, s32 *, 0xF24) = (s32) M2C_FIELD(temp_r0_2, s32 *, 0x2C);
        M2C_FIELD(&data_02143cc0, u32 *, 0xF2C) = (u32) ((u32) (M2C_FIELD(temp_r3, s32 *, 4) & 0x03800000) >> 0x17);
        M2C_FIELD(&data_02143cc0, u32 *, 0xF28) = (u32) ((u32) (M2C_FIELD(temp_r3, s32 *, 4) & 0x700000) >> 0x14);
        M2C_FIELD(&data_02143cc0, s8 *, 0xF30)  = 1;
    }
}
