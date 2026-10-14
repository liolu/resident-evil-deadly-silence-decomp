/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020c440c(void);
void func_020c46d4(M2C_UNK, M2C_UNK);
void func_020c47b8(void);
void func_020d69c0(void);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;

void func_020a4da4(void) {
    if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) == 0) {
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) = 1U;
        func_020c47b8();
        func_020c46d4(0x16, 0);
    }
    func_020c440c();
    if (M2C_FIELD(&data_0213b890, u8 *, 1) == 5) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020d69c0;
    }
}
