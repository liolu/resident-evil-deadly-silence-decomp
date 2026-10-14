/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02105528(void);
void func_0210fce0(void);

extern s32 (*data_0215bccc)();

void func_0210fd00(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        var_r0 = 0;
        if (data_0215bccc != NULL) {
            var_r0 = data_0215bccc();
        }
        if (var_r0 == 0) {
            return;
        }
        func_0210fce0();
        return;
    }
    func_02105528();
}
