/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020da00c(M2C_UNK);
void func_020dd470(void);
void func_020dd47c(void);

extern s8 data_0214eb78;

void func_020d9fa0(void) {
    s32 var_r5;
    s8 *var_r4;

    func_020dd47c();
    var_r4 = &data_0214eb78;
    var_r5 = 0;
    do {
        if (*var_r4 == 1) {
            func_020da00c((s32) var_r4);
        }
        var_r5 += 1;
        var_r4 += 0x44;
    } while (var_r5 < 0x10);
    func_020dd470();
}
