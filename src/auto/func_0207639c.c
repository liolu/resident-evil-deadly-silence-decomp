/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02102360(void);
void func_021023d0(M2C_UNK, M2C_UNK, M2C_UNK);
void func_02102534(void);

void func_0207639c(s32 arg0) {
    func_02102534();
    func_021023d0(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), M2C_FIELD(arg0, s32 *, 8));
    func_02102360();
}
