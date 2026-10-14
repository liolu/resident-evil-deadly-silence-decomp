/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_01ffd2c4(M2C_UNK, M2C_UNK);
void func_02037bf0(void);
void func_020b3a24(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213db04;
extern M2C_UNK data_02144c34;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_02039994(void) {
    s32 temp_r0;

    temp_r0 = func_01ffd2c4((s32) &data_02144c34, 0x20);
    data_027e0018 = temp_r0;
    M2C_FIELD(data_027e000c, s16 *, 0x44) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x44) + temp_r0);
    if (data_027e0018 == 0) {
        func_020b3a24((s32) &data_0213db04, (s32) M2C_FIELD(data_027e000c, u8 *, 0xBF));
    }
    func_02037bf0();
}
