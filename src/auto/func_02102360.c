/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ffae4(M2C_UNK);
void func_021059ac(M2C_UNK);

extern s32 data_02136b8c;
extern s32 data_02158808;
extern s32 data_02158814;
extern s32 data_02158818;
extern s32 data_0215881c;

void func_02102360(void) {
    if (data_02136b8c != -1) {
        func_021059ac(data_02136b8c);
    }
    func_020ffae4(data_02158814);
    data_0215881c = 0;
    data_02158818 = 0;
    data_02158808 = 0;
    data_02158814 = 0;
}
