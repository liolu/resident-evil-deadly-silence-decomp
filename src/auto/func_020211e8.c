/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_01ffd504(M2C_UNK);
M2C_UNK func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020b8110(M2C_UNK, M2C_UNK);

void func_020211e8(s32 arg0) {
    M2C_FIELD(arg0, s16 *, 0xA6) = 0x104;
    if ((u32) (u8) (M2C_FIELD(arg0, u8 *, 0xA) + 0xFA) <= 1U) {
        func_01ffd504(0);
    }
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (M2C_FIELD(arg0, s16 *, 0xA8) - 1);
    if ((M2C_FIELD(arg0, s16 *, 0xA8) == 0) || (M2C_FIELD(arg0, u8 *, 0xA0) != 0)) {
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, s8 *, 0x194) = 1;
        if (M2C_FIELD(arg0, u8 *, 0xA) != 7) {
            func_020b8110(0x4A, 0);
        }
    }
    func_0209109c(0, 0x400, 7);
}
