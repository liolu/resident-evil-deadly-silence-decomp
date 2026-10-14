/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02070438(M2C_UNK);
void func_0210224c(void);
void func_021022a4(M2C_UNK, M2C_UNK, M2C_UNK);
void func_02102318(void);

void func_020762e4(s32 arg0) {
    void *temp_r4;

    func_02102318();
    func_021022a4(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8));
    func_0210224c();
    temp_r4 = M2C_FIELD(arg0, void **, 0x10);
    func_02070438(M2C_FIELD(temp_r4, s32 *, 4));
    M2C_FIELD(temp_r4, s32 *, 4) = 0;
    M2C_FIELD(temp_r4, u8 *, 0) = (u8) (M2C_FIELD(temp_r4, u8 *, 0) | 0x20);
}
