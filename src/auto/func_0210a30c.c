/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02107b0c(void);
M2C_UNK func_02107cf0(M2C_UNK, M2C_UNK);
void func_02107d18(M2C_UNK, M2C_UNK);
void func_0210a39c(M2C_UNK, M2C_UNK, M2C_UNK);

extern u16 data_0215a824;
extern M2C_UNK data_0215a828;

void func_0210a30c(void) {
    if (data_0215a824 != 0) {
        return;
    }
    data_0215a824 = 1;
    func_02107b0c();
    M2C_FIELD(&data_0215a828, s16 *, 0x32) = 0;
    M2C_FIELD(&data_0215a828, s16 *, 0x36) = 0;
    M2C_FIELD(&data_0215a828, s16 *, 0xC) = 0;
    M2C_FIELD(&data_0215a828, s32 *, 0) = 0;
    M2C_FIELD(&data_0215a828, s32 *, 0x10) = 0;
    M2C_FIELD(&data_0215a828, s16 *, 0x30) = 0;
    M2C_FIELD(&data_0215a828, s16 *, 0x34) = 0;
    do {

    } while (func_02107cf0(6, 1) == 0);
    func_02107d18(6, (s32) func_0210a39c);
}
