/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02003b00(M2C_UNK);
void func_0200f644(void);
void func_020fff68(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_02077e68(void) {
    u8 temp_r4;

    M2C_FIELD(&data_02143cc0, s8 *, 0xF) = 3;
    func_020fff68(8);
    func_02003b00(8);
    temp_r4                              = M2C_FIELD(&data_02143cc0, u8 *, 0xE);
    M2C_FIELD(&data_02143cc0, u8 *, 0xE) = 1U;
    func_0200f644();
    M2C_FIELD(&data_02143cc0, u8 *, 0xE) = temp_r4;
}
