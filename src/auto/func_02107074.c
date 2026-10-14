/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02106aa8(void);
M2C_UNK func_02106af0(void);
void func_02106b48(void);
M2C_UNK func_02106c18(void);
void func_02106e6c(M2C_UNK);
M2C_UNK func_02107110(M2C_UNK);

s32 func_02107074(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;

    if (func_02106aa8() == 0) {
        return 0;
    }
    temp_r0_3 = func_02106af0();
    if (temp_r0_3 != 0) {
        return temp_r0_3;
    }
    if (!(arg0 & 1)) {
        return 0;
    }
    if (func_02106c18() > 0) {
        do {

        } while (func_02107110(0) != 0);
        temp_r0_2 = func_02106af0();
        if (temp_r0_2 != 0) {
            return temp_r0_2;
        }
        goto block_12;
    }
    func_02106e6c(1);
block_12:
    func_02106b48();
    do {
        func_02107110(1);
        temp_r0 = func_02106af0();
    } while (temp_r0 == 0);
    return temp_r0;
}
