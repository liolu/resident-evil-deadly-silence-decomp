/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_020deb20(void *, M2C_UNK);
extern M2C_UNK func_020deb88(void *);
extern s32 func_020e6b98(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern M2C_UNK data_0212fe38;
extern M2C_UNK data_0212fe68;

void func_020df120(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 v;

    v = *(s32 *) ((u8 *) arg0 + 0x94);
    if (arg0 == NULL) {
        func_020deb88(&data_0212fe38);
        return;
    }
    if (func_020e6b98(v, arg1, 0, arg2, arg3) >= 0) {
        return;
    }
    func_020deb20(&data_0212fe68, arg1);
}
