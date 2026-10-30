/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207718c(void *);                      /* extern */
M2C_UNK func_020f43ac(void *, s32);                 /* extern */
M2C_UNK func_020f829c(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_0213b38c;

void func_02076ecc(void *arg0) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, s32 *, 8) != 0)) {
        func_020f43ac(arg0 + 0x20, M2C_FIELD(arg0, s32 *, 0x10));
        func_020f829c(&data_0213b38c, M2C_FIELD(arg0, s32 *, 0x10));
        func_0207718c(arg0 + 8);
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
    }
}
