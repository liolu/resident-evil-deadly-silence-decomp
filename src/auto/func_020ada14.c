/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020a0518(void *, u8, u8, M2C_UNK);     /* extern */
s32 func_020ad87c();                                /* extern */
s32 func_020ada7c();                                /* extern */
extern M2C_UNK data_02121eb8;
extern M2C_UNK data_02122024;
extern void *data_027e000c;

void func_020ada14(void) {
    s32 temp_r5;
    s32 temp_r0;
    void *temp_r4;
    u8 temp_r2;
    u8 *temp_r3;
    u8 temp_r1;
    u16 temp_r2b;

    temp_r5  = func_020ad87c();
    temp_r4  = data_027e000c;
    temp_r0  = func_020ada7c();
    temp_r2  = M2C_FIELD(temp_r4, u8 *, 9);
    temp_r3  = (u8 *) &data_02122024 + (temp_r5 * 9);
    temp_r2b = *(u16 *) ((u8 *) &data_02121eb8 + (temp_r0 * 2));
    temp_r1  = temp_r3[temp_r2 & 0xF];
    func_020a0518(temp_r4, temp_r1, (u8) temp_r2b, 0);
}
