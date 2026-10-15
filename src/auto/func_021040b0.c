/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_021040b0(void) {
    u16 *var_r0;

    if (*(u16 *) 0x027FFC10 == 0) {
        var_r0 = (u16 *) 0x027FF814;
    } else {
        var_r0 = (u16 *) 0x027FFC14;
    }
    if (*var_r0 == 1) {
        return 1;
    }
    return 0;
}
