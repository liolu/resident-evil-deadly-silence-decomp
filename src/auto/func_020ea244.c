/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK (*data_0214f780)();

void func_020ea244(s32 arg0) {
    if (data_0214f780 == NULL) {
        return;
    }
    data_0214f780(arg0);
}
