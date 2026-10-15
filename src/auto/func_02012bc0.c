/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0200fcc4(M2C_UNK);
void func_02010f2c(M2C_UNK);
void func_020c46b4(M2C_UNK);

extern M2C_UNK data_0214ccc0;

void func_02012bc0(s32 arg0, s32 arg1) {
    func_02010f2c(arg1);
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF84) = 0;
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF88) = 0;
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF8C) = 0;
    func_0200fcc4(arg1);
    func_020c46b4(0);
}
