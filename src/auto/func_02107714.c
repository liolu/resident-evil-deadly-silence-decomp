/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021046b8(M2C_UNK, M2C_UNK);
void func_02106a34(void);
void func_02106a48(void);

void func_02107714(s32 arg0, s32 arg1, s32 arg2) {
    func_02106a48();
    M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0x3C) = arg2;
    func_021046b8(arg0 + 0x3C + (arg1 * 4), 4);
    func_02106a34();
}
