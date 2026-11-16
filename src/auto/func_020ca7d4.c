/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern M2C_UNK data_02125c50;
extern M2C_UNK data_0213b890;

s32 func_020ca7d4(void) {
    u32 var_ip;
    u8 *base;
    u8 *tbl;

    base   = (u8 *) M2C_FIELD(&data_0213b890, void **, 0x4C);
    var_ip = 0;
    tbl    = (u8 *) &data_02125c50;
    goto cond;
body:
    if (tbl[var_ip] != base[var_ip + 2]) {
        return 0;
    }
    var_ip += 1;
cond:
    if (var_ip < 9U) {
        goto body;
    }
    func_020b5540(1);
    func_020b82fc(0xD6);
    return 1;
}
