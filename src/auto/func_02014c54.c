/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02014c98(M2C_UNK);

extern void *data_0213730c;

void func_02014c54(s32 arg0) {
    s32 var_ip;

    var_ip = 1;
    if (!(M2C_FIELD(data_0213730c, s32 *, 0xC) & (1 << M2C_FIELD(arg0, u8 *, 0xAC)))) {
        var_ip = 0;
    }
    *M2C_FIELD(arg0, s32 **, 0xB8) = var_ip;
    M2C_FIELD(arg0, void (**)(s32), 0x1C) = func_02014c98;
    M2C_FIELD(arg0, s8 *, 0x90) = 2;
}
