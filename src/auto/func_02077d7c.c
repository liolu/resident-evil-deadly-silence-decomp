/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02003b00(M2C_UNK);
void func_02072cb4(void);
void func_020fff68(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_02077d7c(void) {
    M2C_FIELD(&data_02143cc0, s8 *, 0xF) = 6;
    func_020fff68(8);
    func_02003b00(8);
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 1;
    func_02072cb4();
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
}
