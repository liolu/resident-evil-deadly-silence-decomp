/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02072550(void);
void func_020b84ec(void);

extern M2C_UNK data_0213b2b4;

void func_0209b198(void) {
    func_020b84ec();
    M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_02072550;
}
