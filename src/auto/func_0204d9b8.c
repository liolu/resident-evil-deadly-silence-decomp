/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_0204b4c0(void *);                      /* extern */
s32 func_0204db14(void *);                          /* extern */
s32 func_0204dbb0(void *);                          /* extern */
s32 func_0204dc40(void *);                          /* extern */
s32 func_020ad804();                                /* extern */
s32 func_020d9764(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0018;
extern s32 data_027e0020;

void func_0204d9b8(void *arg0) {
    void *temp_r1;

    func_01ffd214(&data_02144c34, 0x30);
    if (func_020ad804() != 0) {
        data_027e0020 = func_020d9764(&data_02144c34);
        if (func_0204dc40(arg0) != 0) {
            M2C_FIELD(arg0, s8 *, 0x90) = 1;
            M2C_FIELD(arg0, s8 *, 0x91) = 1;
            M2C_FIELD(arg0, s8 *, 0x92) = 2;
            M2C_FIELD(arg0, s8 *, 0x93) = 0;
        }
        if (func_0204dbb0(arg0) != 0) {
            M2C_FIELD(arg0, s8 *, 0x90) = 1;
            M2C_FIELD(arg0, s8 *, 0x91) = 1;
            M2C_FIELD(arg0, s8 *, 0x92) = 2;
            M2C_FIELD(arg0, s8 *, 0x93) = 0;
        }
        if (((s32) data_027e0018 < 0x1B58) && ((s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0x9C), s8 *, 0x17F) > 4)) {
            M2C_FIELD(arg0, s8 *, 0x90) = 1;
            M2C_FIELD(arg0, s8 *, 0x91) = 1;
            M2C_FIELD(arg0, s8 *, 0x92) = 3;
            M2C_FIELD(arg0, s8 *, 0x93) = 0;
        }
        if (func_0204db14(arg0) != 0) {
            M2C_FIELD(arg0, s8 *, 0x90) = 1;
            M2C_FIELD(arg0, s8 *, 0x91) = 1;
            M2C_FIELD(arg0, s8 *, 0x92) = 4;
            M2C_FIELD(arg0, s8 *, 0x93) = 0;
        }
        if ((s32) (M2C_FIELD(&data_02144bc0, s16 *, 0xD8) - 0xA) < 0) {
            temp_r1 = M2C_FIELD(arg0, void **, 0x9C);
            if (M2C_FIELD(temp_r1, u8 *, 0x17E) == 0) {
                M2C_FIELD(temp_r1, s8 *, 0x18F) = 1;
                M2C_FIELD(arg0, s8 *, 0x90)     = 1;
                M2C_FIELD(arg0, s8 *, 0x91)     = 1;
                M2C_FIELD(arg0, s8 *, 0x92)     = 3;
                M2C_FIELD(arg0, s8 *, 0x93)     = 0;
            }
        }
    }
    func_0204b4c0(arg0);
}
