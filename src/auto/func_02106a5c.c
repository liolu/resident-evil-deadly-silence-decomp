/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0210461c(M2C_UNK);
void func_02107244(void);
void func_0210740c(void);

extern s32 data_02158be0;
extern M2C_UNK data_02158be4;

void func_02106a5c(void) {
    if (data_02158be0 != 0) {
        return;
    }
    data_02158be0 = 1;
    func_0210461c((s32) &data_02158be4);
    func_02107244();
    func_0210740c();
}
