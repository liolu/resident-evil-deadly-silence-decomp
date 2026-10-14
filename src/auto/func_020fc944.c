/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020fd600(void);
void func_021067e4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02106d0c(void);
void func_02106ddc(M2C_UNK);
void func_02106e6c(M2C_UNK);

void func_020fc944(void) {
    s32 temp_r4;

    func_020fd600();
    func_021067e4(0, 0, 0, 0);
    temp_r4 = func_02106d0c();
    func_02106e6c(1);
    func_02106ddc(temp_r4);
}
