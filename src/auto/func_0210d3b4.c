/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02105528(void);
void func_0210d364(void);

extern s32 data_0215b1a0;
extern s32 (*data_0215b1a4)();

void func_0210d3b4(s32 arg0, s32 arg1) {
    s32 var_r0;

    if ((arg1 & 0x3F) == 0x11) {
        var_r0        = 1;
        data_0215b1a0 = 1;
        if (data_0215b1a4 != NULL) {
            var_r0 = data_0215b1a4();
        }
        if (var_r0 == 0) {
            return;
        }
        func_0210d364();
        return;
    }
    func_02105528();
}
