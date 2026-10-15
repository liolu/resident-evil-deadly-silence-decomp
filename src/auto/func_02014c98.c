/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02014c54(M2C_UNK);

extern void *data_0213730c;

void func_02014c98(s32 arg0) {
    void *temp_ip;
    void *temp_lr;

    temp_ip                        = M2C_FIELD(arg0, void **, 0xB0);
    M2C_FIELD(temp_ip, s32 *, 0xC) = (s32) (M2C_FIELD(temp_ip, s32 *, 0xC) & ~0x1F0000);
    temp_lr                        = M2C_FIELD(arg0, void **, 0xB0);
    M2C_FIELD(temp_lr, s32 *, 0xC) = (s32) (M2C_FIELD(temp_lr, s32 *, 0xC) | (M2C_FIELD(data_0213730c, u8 *, 9) << 0x10));
    M2C_FIELD(arg0, void (**)(s32), 0x14) = func_02014c54;
    M2C_FIELD(arg0, s8 *, 0x8E)           = 2;
}
