/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02017b4c(M2C_UNK);
M2C_UNK func_020a9d58(void);

void func_02015680(s32 arg0) {
    func_02017b4c(arg0);
    M2C_FIELD(arg0, s8 *, 6) = (s8) (func_020a9d58() & 7);
}
