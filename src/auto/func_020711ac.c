/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020889c4(void);
void func_02093b80(void);

extern M2C_UNK data_0213b2b4;

void func_020711ac(void) {
    func_020889c4();
    M2C_FIELD(&data_0213b2b4, s8 *, 0xB4)        = 6;
    M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_02093b80;
}
