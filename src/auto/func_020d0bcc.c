/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020b9938(void);
void func_020b9aa4(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020d0bcc(void) {
    func_020b9aa4(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0xF6);
    func_020b9938();
}
