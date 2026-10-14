/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020e99ac(M2C_UNK);
void func_020e9a94(M2C_UNK);

void func_020ec1b4(s32 arg0) {
    void **temp_r0;

    temp_r0 = M2C_FIELD(arg0, void ***, 0x10);
    if (M2C_FIELD(*temp_r0, s32 (**)(void **, M2C_UNK), 0x24)(temp_r0, 1) < 0x24) {
        return;
    }
    func_020e9a94(M2C_FIELD(arg0, s32 *, 0));
    func_020e99ac(M2C_FIELD(arg0, s32 *, 0));
    M2C_FIELD(arg0, s8 *, 0xB) = 1;
    M2C_FIELD(arg0, s8 *, 9) = 2;
}
