/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02106b48(void);
M2C_UNK func_02106c18(void);
M2C_UNK func_02106c78(void);
void func_02106e6c(M2C_UNK);
M2C_UNK func_02107110(M2C_UNK);

void func_02106d4c(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_02106c78();
    if (temp_r0 >= arg0) {
        return;
    }
    if ((s32) (temp_r0 + func_02106c18()) >= arg0) {
        do {

        } while (func_02107110(0) != 0);
        if (func_02106c78() >= arg0) {
            return;
        }
        goto block_8;
    }
    func_02106e6c(1);
block_8:
    func_02106b48();
    do {
        func_02107110(1);
    } while (func_02106c78() < arg0);
}
