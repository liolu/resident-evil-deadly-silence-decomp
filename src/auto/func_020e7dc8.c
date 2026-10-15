/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_021126e0(M2C_UNK, M2C_UNK, M2C_UNK);

extern s32 data_02153ce8;
extern M2C_UNK (*data_02153cec)(s32, M2C_UNK *);
extern M2C_UNK data_02153cf0;

void func_020e7dc8(s32 arg0) {
    func_021126e0((s32) &data_02153cf0, arg0, 0xFF);
    if (data_02153cec == NULL) {
        return;
    }
    data_02153cec(data_02153ce8, &data_02153cf0);
}
