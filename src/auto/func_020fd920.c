/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020fd864(M2C_UNK, M2C_UNK);
void func_020fd8d8(M2C_UNK);
void func_020fda38(M2C_UNK);

extern s32 data_02157d5c;
extern M2C_UNK data_02158218;

void func_020fd920(s32 arg0) {
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x10C) << 0x1F) >> 0x1F) == 0) {
        return;
    }
    func_020fd8d8(arg0);
    M2C_FIELD(arg0, M2C_UNK (**)(s32), 0x160)(arg0);
    func_020fd864((s32) &data_02158218, arg0);
    if (data_02157d5c != 0) {
        func_020fd864(data_02157d5c + 0x4AC, arg0);
    }
    func_020fda38(arg0);
}
