/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020deb88(M2C_UNK *);                   /* extern */
M2C_UNK func_020e1920();                            /* extern */
M2C_UNK func_020e6618();                            /* extern */
M2C_UNK func_020e6624();                            /* extern */
M2C_UNK func_020ea244(void *);                      /* extern */
M2C_UNK func_020ebefc(s32, s32, s32);               /* extern */
s32 func_020ec2c0(s32, M2C_UNK, void *, s32, s32);  /* extern */
M2C_UNK func_020ec47c();                            /* extern */
extern M2C_UNK data_02132590;
extern M2C_UNK data_021325b8;
extern M2C_UNK data_021325e4;
extern M2C_UNK *data_0214efb8;
extern M2C_UNK *data_0214efbc;
extern M2C_UNK *data_0214efc0;
extern M2C_UNK *data_0214efc4;
extern M2C_UNK *data_0214efd4;
extern M2C_UNK *data_0214f780;
extern M2C_UNK func_020ea0c8;
extern M2C_UNK func_020ea1b4;
extern M2C_UNK func_020ea1c0;
extern M2C_UNK func_020ea1cc;
extern M2C_UNK func_020ebecc;
extern M2C_UNK func_020ec258;

void func_020ea278(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 temp_r5;
    void *temp_r4;
    void *temp_r6;

    if ((arg0 == NULL) || (arg1 == 0)) {
        func_020deb88(&data_02132590);
        return;
    }
    if (arg2 < 0x3000) {
        func_020deb88(&data_021325b8);
        return;
    }
    func_020e1920();
    func_020ea244(arg0);
    func_020ec47c();
    temp_r4 = M2C_FIELD(arg0, void **, 4);
    temp_r5 = M2C_FIELD(arg0, volatile s32 *, 0x10);
    temp_r6 = M2C_FIELD(temp_r4, void **, 4);
    func_020e6624();
    temp_r0 = func_020ec2c0(temp_r5, 1, arg0 + 0x18, arg1, arg2);
    if (temp_r0 == 0) {
        func_020deb88(&data_021325e4);
        return;
    }
    M2C_FIELD(temp_r6, volatile s32 *, 0xB4) = temp_r0;
    data_0214f780                            = &func_020ea1cc;
    data_0214efc4                            = &func_020ea0c8;
    data_0214efb8                            = &func_020ea1b4;
    data_0214efbc                            = &func_020ea1c0;
    data_0214efc0                            = &func_020ec258;
    data_0214efd4                            = &func_020ebecc;
    func_020ebefc(temp_r0, M2C_FIELD(temp_r4, volatile s32 *, 0x50), M2C_FIELD(temp_r4, volatile s32 *, 0x54));
    func_020e6618();
}
