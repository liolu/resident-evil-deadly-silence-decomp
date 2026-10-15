/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02091d4c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_020a449c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_02091d4c(arg1, arg3, arg0, (0xFFF & (arg2 * 8)) | 0x05001000);
}
