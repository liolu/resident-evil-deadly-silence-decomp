/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ff9f0(M2C_UNK);
void func_021059ac(M2C_UNK);

extern s32 data_02136b8c;
extern s32 data_0215880c;
extern s32 data_02158810;

void func_0210224c(void) {
    if (data_02136b8c != -1) {
        func_021059ac(data_02136b8c);
    }
    func_020ff9f0(data_02158810);
    data_02158810 = 0;
    data_0215880c = 0;
}
