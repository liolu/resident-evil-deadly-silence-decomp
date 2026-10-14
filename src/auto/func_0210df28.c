/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0210d918(void);

s32 func_0210df28(void) {
    if (func_0210d918() != 0) {
        return 0x8000;
    }
    return (s32) *(u16 *)0x027FFCFA;
}
