/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020deb88(M2C_UNK);
void func_020e1920(M2C_UNK);
void func_020e6618(void);
void func_020e6624(void);
void func_020ec204(M2C_UNK);
void func_020ec268(M2C_UNK);
void func_020ec440(void);

extern M2C_UNK data_02132568;

void func_020ea1cc(s32 arg0) {
    s32 temp_r4;
    void *temp_r5;

    if (arg0 == 0) {
        func_020deb88((s32) &data_02132568);
        return;
    }
    func_020e1920(arg0);
    temp_r5 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 4);
    temp_r4 = M2C_FIELD(temp_r5, volatile s32 *, 0xB4);
    if (temp_r4 == 0) {
        return;
    }
    func_020e6624();
    func_020ec204(temp_r4);
    func_020ec268(temp_r4);
    M2C_FIELD(temp_r5, volatile s32 *, 0xB4) = 0;
    func_020e6618();
    func_020ec440();
}
