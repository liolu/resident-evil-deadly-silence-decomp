/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02070088(M2C_UNK *, M2C_UNK, u8, M2C_UNK); /* extern */
s32 func_020ad87c();                                /* extern */
extern M2C_UNK data_0211da7c;
extern M2C_UNK data_0211daac;
extern M2C_UNK data_02122024;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213afec;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;
extern M2C_UNK data_0214ccc0;
extern void *data_027e000c;

void func_02072dc8(s32 arg0, s32 arg1) {
    s32 temp_r0;
    u8 temp_r1;
    u8 var_r2;

    temp_r0 = func_020ad87c();
    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 9) & 0xF;
    if (M2C_FIELD(&data_02144cc0, u8 *, 0xE3) & 1) {
        var_r2 = *(s8 *) (temp_r1 + ((temp_r0 * 9) + (s32) &data_02122024));
    } else if (M2C_FIELD(&data_0213ad48, u8 *, 9) == 1) {
        var_r2 = *(s8 *) (temp_r1 + ((temp_r0 * 0xF) + (s32) &data_0211daac));
    } else {
        var_r2 = *(s8 *) (temp_r1 + ((temp_r0 * 0xF) + (s32) &data_0211da7c));
    }
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF84)   = func_02070088(&data_0213afec, 0, var_r2, 1);
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF88)   = arg0;
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF8C)   = arg1;
    M2C_FIELD(&data_0214ccc0, void **, 0xF90) = (void *) data_027e000c;
    M2C_FIELD(&data_02143cc0, s8 *, 0xF)      = 4;
}