/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02077f6c(M2C_UNK);
void func_0209f814(void);
void func_0209fa9c(M2C_UNK);
void func_02105528(void);

extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213b2b4;

void func_0209fad8(void) {
    if (func_02077f6c(0x2FC8) == 0) {
        func_02105528();
    }
    M2C_FIELD(&data_0213b2b4, s8 *, 1) = 0;
    func_0209fa9c(1);
    func_0209f814();
    M2C_FIELD(&data_0213af7c, s8 *, 0x20)  = 3;
    M2C_FIELD(&data_0213af7c, s16 *, 0x28) = 0;
    M2C_FIELD(&data_0213af7c, s8 *, 0x26)  = 0;
    M2C_FIELD(&data_0213af7c, s8 *, 0x27)  = 0;
}
