/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_020b8110(M2C_UNK, M2C_UNK);
typedef void (*Handler)(void *);
extern Handler data_0211c274[];

typedef struct {
    u8 pad[0x92];
    u8 kind;
} Obj92;

void func_02020c8c(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + M2C_FIELD(arg0, s16 *, 0x182));
    if (func_0209109c(1, 0x200, 5) != 0) {
        func_020b8110(0x44, 0);
    }
    data_0211c274[((Obj92 *) arg0)->kind](arg0);
}
