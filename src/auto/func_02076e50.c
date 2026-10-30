/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207718c(void *);                      /* extern */
M2C_UNK func_0207729c(void *);                      /* extern */
M2C_UNK func_0209ffcc(void *);                      /* extern */
M2C_UNK func_020f43ac(void *, s32);                 /* extern */
M2C_UNK func_020f829c(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_0213b38c;

void func_02076e50(void **arg0) {
    void *temp_r4;

    temp_r4 = *arg0;
    *arg0   = NULL;
    if (temp_r4 != NULL) {
        func_0209ffcc(temp_r4);
        if (M2C_FIELD(temp_r4, s32 *, 8) != 0) {
            func_020f43ac(temp_r4 + 0x20, M2C_FIELD(temp_r4, s32 *, 0x10));
            func_020f829c(&data_0213b38c, M2C_FIELD(temp_r4, s32 *, 0x10));
            func_0207718c(temp_r4 + 8);
        }
        if (M2C_FIELD(temp_r4, s32 *, 4) != 0) {
            func_0207729c(temp_r4 + 4);
        }
        M2C_FIELD(temp_r4, s32 *, 0xC)  = 0;
        M2C_FIELD(temp_r4, s32 *, 0x10) = 0;
        M2C_FIELD(temp_r4, s16 *, 0)    = 0;
    }
}
