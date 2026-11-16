/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void *);
s32 func_01ffd504(s32);
void func_0201ece0(void *);
s32 func_0209109c(s32, s32, s32);
void func_020b8110(s32, s32);
extern Fn data_0211c268[];

void func_02021780(void *arg0) {
    s16 temp_r4;

    if ((u32) M2C_FIELD(arg0, u8 *, 0x92) < 2U) {
        temp_r4                      = M2C_FIELD(arg0, s16 *, 0xA6);
        M2C_FIELD(arg0, s16 *, 0xA6) = (s16) (temp_r4 - 0xF0);
        func_01ffd504(0);
        M2C_FIELD(arg0, s16 *, 0xA6) = temp_r4;
    }
    if (func_0209109c(1, 0x200, 5) != 0) {
        func_020b8110(0x44, 0);
    }
    data_0211c268[M2C_FIELD(arg0, u8 *, 0x92)](arg0);
    func_0201ece0(arg0);
}
