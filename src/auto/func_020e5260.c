/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e4a9c();                            /* extern */
M2C_UNK func_020e4aac();                            /* extern */
s32 func_021093c0(void *, s32, s32);                /* extern */
extern s32 data_021528bc;

void func_020e5260(void *arg0) {
    s32 var_r0;

    if (M2C_FIELD(arg0, s8 *, 1) == 2) {
        if (M2C_FIELD(arg0, s32 *, 0x6C) == 1) {
            M2C_FIELD(arg0, s32 *, 0x6C) = 0;
            M2C_FIELD(arg0, s32 *, 0x68) = func_021093c0(arg0 + 4, M2C_FIELD(arg0, s32 *, 0x48), M2C_FIELD(arg0, s32 *, 0x68));
            M2C_FIELD(arg0, s32 *, 0x70) = 1;
        }
        if (M2C_FIELD(arg0, s32 *, 0x70) == 1) {
            if (M2C_FIELD(arg0, s32 *, 0x10) & 1) {
                var_r0 = 1;
            } else {
                var_r0 = 0;
            }
            if (var_r0 == 0) {
                func_020e4aac();
                M2C_FIELD(arg0, s32 *, 0x70) = 0;
                M2C_FIELD(arg0, s8 *, 1) = 1;
                M2C_FIELD(arg0, s32 *, 0x58) = (s32) (M2C_FIELD(arg0, s32 *, 0x58) + M2C_FIELD(arg0, s32 *, 0x60));
                M2C_FIELD(arg0, s32 *, 0x5C) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) * M2C_FIELD(arg0, s32 *, 0x4C));
                M2C_FIELD(arg0, s32 *, 0x60) = 0;
                func_020e4a9c();
            }
        }
    }
    data_021528bc = 0;
}
