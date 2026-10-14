/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020478fc();                                /* extern */
M2C_UNK func_0204791c();                            /* extern */
M2C_UNK func_02047970(void *);                      /* extern */
M2C_UNK func_02048144(u16, M2C_UNK);                /* extern */
M2C_UNK func_02090234(u8, M2C_UNK);                 /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020a835c(void *);                      /* extern */
M2C_UNK func_020a840c(s32);                         /* extern */
extern u8 data_02137360;
extern u8 data_02137364;
extern u8 data_0213736c;
extern void *data_02137370;

s32 func_02047eb0(void *arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r0;
    s32 temp_r4;
    u8 temp_r1;
    u8 temp_r1_2;

    temp_r4 = func_0209109c(arg1, arg2, arg3);
    temp_r1 = M2C_FIELD(data_02137370, u8 *, 0x18);
    if ((temp_r1 != 0) && (temp_r1 == M2C_FIELD(arg0, u8 *, 0xA2))) {
        func_02048144(M2C_FIELD(data_02137370, u16 *, 0x1A), 0);
    }
    temp_r1_2 = M2C_FIELD(data_02137370, u8 *, 0x19);
    if ((temp_r1_2 != 0) && (temp_r1_2 == M2C_FIELD(arg0, u8 *, 0xA2))) {
        func_02048144(M2C_FIELD(data_02137370, u16 *, 0x1C), 0);
    }
    if ((M2C_FIELD(arg0, u8 *, 0xA1) == 0xC) && (M2C_FIELD(arg0, u8 *, 0xA2) == data_02137360)) {
        func_0204791c();
    }
    func_02047970(arg0);
    if (M2C_FIELD(arg0, u8 *, 0xA2) == data_02137360) {
        func_02090234(data_02137364, 1);
    }
    if (M2C_FIELD(arg0, u8 *, 0xA2) == data_0213736c) {
        func_02090234(data_02137364, 3);
    }
    if (func_020478fc() != 0) {
        func_02090234(data_02137364, 1);
    }
    temp_r0 = M2C_FIELD(arg0, s16 *, 0x94) & 0x8000;
    if (temp_r0 == 0) {
        func_020a840c(temp_r0);
    }
    func_020a835c(arg0);
    return temp_r4;
}
