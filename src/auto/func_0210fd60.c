/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02105528(void);

extern s16 data_0215bcc0;

void func_0210fd60(s32 arg0, s32 arg1) {
    if ((arg1 & 0x3F) == 1) {
        data_0215bcc0 = 1;
        return;
    }
    func_02105528();
}
