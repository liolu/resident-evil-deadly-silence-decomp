/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e4a9c(void);
void func_020e4aac(void);

extern M2C_UNK data_02152588;

void func_020e46dc(s32 arg0, s32 arg1) {
    func_020e4aac();
    M2C_FIELD(&data_02152588, s32 *, 0) = arg0;
    M2C_FIELD(&data_02152588, s32 *, 4) = arg1;
    func_020e4a9c();
}
