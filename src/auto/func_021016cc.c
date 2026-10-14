/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ffce8(M2C_UNK);
void func_021059ac(M2C_UNK);

extern s32 data_02136b8c;
extern s32 data_021587fc;
extern s32 data_02158800;
extern s32 data_02158804;

void func_021016cc(void) {
    if (data_02136b8c != -1) {
        func_021059ac(data_02136b8c);
    }
    func_020ffce8(data_02158804);
    data_02158804 = 0;
    data_02158800 = 0;
    data_021587fc = 0;
}
