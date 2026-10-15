/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern s32 data_02153248;
extern M2C_UNK (*data_0215324c)(s32, s32);
extern s32 data_02153250;

void func_020e6730(void) {
    if (data_0215324c == NULL) {
        return;
    }
    data_0215324c(data_02153248, data_02153250);
}
