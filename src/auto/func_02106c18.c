/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02106c38(void);
M2C_UNK func_02106c78(void);

s32 func_02106c18(void) {
    s32 temp_r4;

    temp_r4 = func_02106c78();
    return (0x100 - temp_r4) - func_02106c38();
}
