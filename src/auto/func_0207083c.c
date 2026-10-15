/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02059968(void);
void func_020708ac(void);
void func_020b52a0(void);
void func_020b5728(M2C_UNK);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

void func_0207083c(void) {
    func_020b5728(M2C_FIELD(&data_0213daa8, s32 *, 8));
    func_02059968();
    func_020b52a0();
    M2C_FIELD(&data_0213ad98, s32 *, 0x10) = 0;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0x20);
    func_020708ac();
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x40000) {
        M2C_FIELD(&data_02143cc0, s8 *, 4) = 0;
    }
}
