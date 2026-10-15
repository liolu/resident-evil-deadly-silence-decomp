/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_020b7bcc(M2C_UNK);
void func_020b7e4c(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213af7c;

void func_020908e4(void) {
    if (func_020b7bcc(0) != 6) {
        func_020b7e4c(0, 6);
    }
    M2C_FIELD(&data_0213af7c, s8 *, 0x22) = 0;
    M2C_FIELD(&data_0213af7c, s8 *, 0x23) = 0;
}
