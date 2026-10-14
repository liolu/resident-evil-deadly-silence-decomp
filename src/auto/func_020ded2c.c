/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020d9d64(void);
void func_020dd470(void);
void func_020dd47c(void);
void func_020dd488(void);
void func_020debe0(void);
void func_020e02ac(void);
void func_020e1278(void);
void func_020e1b9c(void);
void func_020e1d50(M2C_UNK);
void func_020e4038(void);
void func_020e41a4(void);
void func_020e432c(void);
void func_020e448c(void);
void func_020e48a0(M2C_UNK, M2C_UNK);
void func_020e49d8(M2C_UNK);
void func_020e6e64(void);
void func_020e736c(void);

extern M2C_UNK data_0212fd78;
extern s32 data_0214f2f8;
extern s32 data_0214f300;
extern s32 data_0214f304;
extern s8 data_0214f308;

void func_020ded2c(void) {
    s32 temp_r1;
    s32 var_r6;
    s8 *var_r5;

    temp_r1 = data_0214f304 - 1;
    data_0214f304 = temp_r1;
    if (temp_r1 != 0) {
        return;
    }
    func_020e1b9c();
    func_020e736c();
    func_020d9d64();
    func_020e1278();
    func_020e6e64();
    func_020dd47c();
    func_020e48a0(2, 1);
    func_020e48a0(4, data_0214f2f8);
    func_020e48a0(5, data_0214f300);
    func_020e448c();
    func_020e02ac();
    func_020debe0();
    func_020e41a4();
    func_020e4038();
    func_020e432c();
    func_020dd470();
    func_020dd488();
    var_r6 = 0;
    var_r5 = &data_0214f308;
    do {
        if (*var_r5 != 0) {
            func_020e49d8((s32) &data_0212fd78);
            func_020e1d50((s32) var_r5);
        }
        var_r6 += 1;
        var_r5 += 0xC4;
    } while (var_r6 < 2);
}
