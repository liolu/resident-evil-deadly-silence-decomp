/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02103818(s32 arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0) != 0) {
        *M2C_FIELD(arg0, s8 **, 4) = (s8) arg1;
        M2C_FIELD(arg0, s32 *, 0)  = (s32) (M2C_FIELD(arg0, s32 *, 0) - 1);
    }
    M2C_FIELD(arg0, s8 **, 4) = (s8 *) (M2C_FIELD(arg0, s8 **, 4) + 1);
}
