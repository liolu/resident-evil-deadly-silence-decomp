/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020059ac(void);
void func_020c46b4(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_020c347c(void) {
    M2C_FIELD(&data_02143cc0, s8 *, 0x10) = 0;
    func_020059ac();
    func_020c46b4(0);
}
