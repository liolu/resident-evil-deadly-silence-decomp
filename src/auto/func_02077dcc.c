/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020ff678(void);
void func_020ff9d0(M2C_UNK);

extern M2C_UNK data_02143cc0;

void func_02077dcc(void) {
    M2C_FIELD(&data_02143cc0, s8 *, 0xF) = 5;
    func_020ff678();
    func_020ff9d0(8);
    *(s32 *) 0x04000064 = 0x81370010;
}
