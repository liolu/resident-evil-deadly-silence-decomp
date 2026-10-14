#include "m2c.h"
#include "engine.h"

void func_02072550(void);
void func_020d69c0(void);

extern M2C_UNK data_0213ad48;
extern u16 data_0213ad84;
extern M2C_UNK data_0213b2b4;

void func_020ae06c(void) {
    if (data_0213ad84 != 0) {
        return;
    }
    if ((M2C_FIELD(&data_0213ad48, u8 *, 1) == 9) && (M2C_FIELD(&data_0213b2b4, u8 *, 0xB7) != 0)) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020d69c0;
        return;
    }
    M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_02072550;
}
