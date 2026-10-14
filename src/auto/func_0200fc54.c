/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020f39e4(M2C_UNK);
M2C_UNK func_020f3bd8(M2C_UNK);
void func_020f81c4(void);
void func_02100e08(void);
M2C_UNK func_02104778(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b2b4;

void func_0200fc54(void) {
    func_02100e08();
    func_020f81c4();
    M2C_FIELD(&data_0213b2b4, u16 *, 0xBC) = (u16) func_020f39e4(0x20);
    M2C_FIELD(&data_0213b2b4, s32 *, 0xC0) = func_02104778(0, (s32) M2C_FIELD(&data_0213b2b4, u16 *, 0xBC), 4);
    M2C_FIELD(&data_0213b2b4, u16 *, 0xBE) = (u16) func_020f3bd8(0x20);
    M2C_FIELD(&data_0213b2b4, s32 *, 0xC4) = func_02104778(0, (s32) M2C_FIELD(&data_0213b2b4, u16 *, 0xBE), 4);
}
