#include "m2c.h"
#include "engine.h"

void func_020c9614(void);

extern M2C_UNK data_0213b890;

void func_020c93b4(void) {
    void *temp_r1;

    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    M2C_FIELD(temp_r1, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_r1, u16 *, 0x2C) - 0x800);
    func_020c9614();
}
