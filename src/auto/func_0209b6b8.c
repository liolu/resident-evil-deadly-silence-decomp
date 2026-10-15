/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02098294(void);
void func_0209fb40(void);
void func_020b6314(void);
void func_020c440c(void);
void func_020c46d4(M2C_UNK, M2C_UNK);
void func_020c47b8(void);

extern s32 data_02137ed8;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;

void func_0209b6b8(void) {
    data_02137ed8 = M2C_FIELD(&data_0213b890, s32 *, 0x4C);
    if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) == 0) {
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) = 1U;
        func_020c47b8();
        func_020c46d4(0x24, 0);
    }
    func_020c440c();
    if (M2C_FIELD(&data_0213b890, u8 *, 1) == 5) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_0209fb40;
    }
    func_02098294();
    func_020b6314();
}
