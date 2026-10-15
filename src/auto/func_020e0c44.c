/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e03b0(void);
void func_020e03bc(void);

void func_020e0c44(s32 arg0) {
    func_020e03bc();
    if ((M2C_FIELD(arg0, s8 *, 1) == 2) && (M2C_FIELD(arg0, s8 *, 2) == 1)) {
        M2C_FIELD(arg0, s8 *, 0x48) = 1;
        if (M2C_FIELD(arg0, s8 *, 0x47) == 1) {
            M2C_FIELD(arg0, s8 *, 0x47) = 0;
        }
    } else {
        M2C_FIELD(arg0, s8 *, 1) = 1;
    }
    func_020e03b0();
}
