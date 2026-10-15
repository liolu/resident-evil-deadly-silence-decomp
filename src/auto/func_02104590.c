/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02103b00(M2C_UNK);
void func_021044ac(M2C_UNK, M2C_UNK);
M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

extern M2C_UNK data_02158894;

void func_02104590(s32 arg0) {
    s32 temp_r0;
    s32 temp_r4;
    s32 temp_r7;

    temp_r4 = func_021054ac();
    temp_r7 = M2C_FIELD(&data_02158894, s32 *, 8);
loop_1:
    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r0 == 0) {
        M2C_FIELD(arg0, s32 *, 4) = temp_r7;
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
        func_021044ac(temp_r7, arg0);
    } else if (temp_r0 == temp_r7) {
        M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + 1);
    } else {
        M2C_FIELD(temp_r7, s32 *, 0x78) = arg0;
        func_02103b00(arg0);
        M2C_FIELD(temp_r7, s32 *, 0x78) = 0;
        goto loop_1;
    }
    func_021054c0(temp_r4);
}
