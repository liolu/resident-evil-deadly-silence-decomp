/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020058d0(void);
void func_0200648c(void);
void func_02078098(void);
void func_020d91a4(void);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_027e0000;

void func_020782c0(void) {
    func_02078098();
    M2C_FIELD(&data_0213b2b4, s8 *, 2)  = (s8) (M2C_FIELD(&data_0213b2b4, s8 *, 2) - 1);
    M2C_FIELD(&data_0213b2b4, s32 *, 4) = (s32) (M2C_FIELD(&data_0213b2b4, s32 *, 4) + 1);
    if (((s32) M2C_FIELD(&data_0213b2b4, s8 *, 2) < 0) && (M2C_FIELD(&data_0213b2b4, s8 *, 3) != 0)) {
        M2C_FIELD(&data_0213b2b4, s8 *, 3) = 0;
        func_0200648c();
    }
    func_020d91a4();
    func_020058d0();
    M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) = (s32) (M2C_FIELD(&data_027e0000, s32 *, 0x3FF8) | 1);
}
