/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020df1ec(M2C_UNK);
M2C_UNK func_020df2c8(M2C_UNK);
M2C_UNK func_020df2d8(M2C_UNK);
M2C_UNK func_020df308(M2C_UNK);
void func_020df388(M2C_UNK, M2C_UNK);
void func_020df390(M2C_UNK, M2C_UNK);
void func_020df398(M2C_UNK, M2C_UNK);
void func_020df3a0(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020df3b4(M2C_UNK, M2C_UNK);
void func_020e2d1c(M2C_UNK);

void func_020e2e88(s32 arg0) {
    s32 temp_r1;
    s32 temp_r4;
    s32 temp_r5;
    s32 temp_r6;
    s32 temp_r7;

    temp_r7 = M2C_FIELD(arg0, s32 *, 4);
    temp_r6 = func_020df308(temp_r7);
    temp_r5 = func_020df2d8(temp_r7);
    temp_r4 = func_020df2c8(temp_r7);
    func_020df1ec(temp_r7);
    func_020df390(temp_r7, 0);
    temp_r1 = temp_r4 - temp_r6;
    M2C_FIELD(arg0, s32 *, 0x90) = temp_r1;
    func_020df398(temp_r7, temp_r1);
    func_020df388(temp_r7, temp_r5);
    func_020df3b4(temp_r7, temp_r6);
    func_020df3a0(temp_r7, (s32) func_020e2d1c, arg0);
}
