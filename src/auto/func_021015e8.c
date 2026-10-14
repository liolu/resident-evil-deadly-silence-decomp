/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ff81c(M2C_UNK);
void func_021059ac(M2C_UNK);

extern s32 data_02136b8c;
extern s32 data_021587f8;

void func_021015e8(void) {
    if (data_02136b8c != -1) {
        func_021059ac(data_02136b8c);
    }
    func_020ff81c(data_021587f8);
    data_021587f8 = 0;
}
