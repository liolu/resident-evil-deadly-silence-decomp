/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e702c(M2C_UNK);
void func_020e70f8(M2C_UNK);
void func_020e7194(M2C_UNK);

void func_020e6f98(s32 arg0) {
    if (M2C_FIELD(arg0, s8 *, 4) == 1) {
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 1) != 2) {
        return;
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x24) <= 0) {
        return;
    }
    if (M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0x20) << 5)), s32 *, 0x50) == 1) {
        func_020e70f8(arg0);
    }
    if (M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0x20) << 5)), s32 *, 0x50) == 2) {
        func_020e702c(arg0);
    }
    if (M2C_FIELD((arg0 + (M2C_FIELD(arg0, s32 *, 0x20) << 5)), s32 *, 0x50) != 0) {
        return;
    }
    func_020e7194(arg0);
}
