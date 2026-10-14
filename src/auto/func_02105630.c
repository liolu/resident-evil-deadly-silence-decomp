/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_021055ec(M2C_UNK, M2C_UNK);
void func_02107b0c(void);
M2C_UNK func_02107cf0(M2C_UNK, M2C_UNK);
void func_02107d18(M2C_UNK, M2C_UNK);

extern u16 data_02158ba0;

void func_02105630(void) {
    if (data_02158ba0 != 0) {
        return;
    }
    data_02158ba0 = 1;
    func_02107b0c();
    do {

    } while (func_02107cf0(0xC, 1) == 0);
    func_02107d18(0xC, (s32) func_021055ec);
}
