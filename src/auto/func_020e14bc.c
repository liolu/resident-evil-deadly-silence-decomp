/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020dd470(void);
void func_020dd47c(void);
void func_020df3cc(void);
void func_020e21e0(M2C_UNK);
void func_020e72fc(void);

extern s8 data_0214f308;
extern s32 data_0214f78c;

void func_020e14bc(void) {
    s32 var_r5;
    s8 *var_r4;

    func_020dd47c();
    if (data_0214f78c != 0) {
        func_020dd470();
        return;
    }
    data_0214f78c = 1;
    func_020dd470();
    func_020df3cc();
    var_r4        = &data_0214f308;
    data_0214f78c = 2;
    var_r5        = 0;
    do {
        if (*var_r4 == 1) {
            func_020e21e0((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0xC4;
    } while (var_r5 < 2);
    data_0214f78c = 3;
    func_020e72fc();
    data_0214f78c = 0;
}
